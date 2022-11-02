#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

vector<pair<pair<int, int>, pair<int, int> > > ess;

int u[101010];
int sz[101010];
vector<pair<int, int> > sta;

int odd=0;

int getu(int a){
	if (u[a]==a) return a;
	return getu(u[a]);
}

void un(int a, int b){
	a=getu(a);
	b=getu(b);
	if (a==b){
		sta.push_back({0, 0});
	}
	else{
		if (sz[a]%2==1&&sz[b]%2==1){
			odd-=2;
		}
		if (sz[a]<sz[b]){
			sta.push_back({a, sz[a]});
			sz[b]+=sz[a];
			u[a]=b;
		}
		else{
			sta.push_back({b, sz[b]});
			sz[a]+=sz[b];
			u[b]=a;
		}
	}
}

void undo(){
	if (sta.back().F>0){
		int t=getu(sta.back().F);
		if (sz[t]%2==0&&sta.back().S%2==1){
			odd+=2;
		}
		sz[sta.back().F]=sta.back().S;
		sz[t]-=sta.back().S;
		u[sta.back().F]=sta.back().F;
	}
	sta.pop_back();
}

const int N=1<<19;
vector<pair<int, int> > se[2*N];
void adde(int a, int b, pair<int, int> e){
	a+=N;
	b+=N;
	while(a<=b){
		if (a%2) se[a++].push_back(e);
		if (!(b%2)) se[b--].push_back(e);
		a/=2;
		b/=2;
	}
}

int ei=0;
int n,m;
int v[303030];

void go(int i, int l, int r){
	for (auto e:se[i]){
		un(e.F, e.S);
	}
	if (l==r&&l<m){
		int added=0;
		while (odd>0&&ei<m){
			if (ess[ei].F.S<=l){
				un(ess[ei].S.F, ess[ei].S.S);
				added++;
			}
			ei++;
		}
		if (odd==0){
			v[l]=ess[ei-1].F.F;
			int asd=ei;
			while (added>0){
				if (ess[ei-1].F.S<=l){
					undo();
					added--;
					adde(ess[ei-1].F.S, l-1, ess[ei-1].S);
				}
				ei--;
			}
			ei=asd;
		}
		else{
			v[l]=-1;
		}
	}
	else if(l<r){
		int mid=(l+r)/2;
		go(i*2+1, mid+1, r);
		go(i*2, l, mid);
	}
	for (int j=0;j<(int)se[i].size();j++){
		undo();
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		u[i]=i;
		sz[i]=1;
	}
	odd=n;
	for (int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		ess.push_back({{c, i}, {a, b}});
	}
	sort(ess.begin(), ess.end());
	go(1, 0, N-1);
	for (int i=0;i<m;i++){
		cout<<v[i]<<'\n';
	}
}