#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;

const int N=1<<20;
ll st[2*N];

void zero(int i, int stl, int str, int l, int r){
	if (l>str||r<stl) return;
	if (st[i]==0) return;
	if (l<=stl&&str<=r){
		st[i]=0;
	}
	if (stl<str){
		int m=(stl+str)/2;
		zero(i*2, stl, m, l, r);
		zero(i*2+1, m+1, str, l, r);
		st[i]=(st[i*2]+st[i*2+1])%mod;
	}
}

ll sum(int a, int b){
	a+=N;
	b+=N;
	ll s=0;
	while (a<=b){
		if (a%2) s+=st[a++];
		if (!(b%2)) s+=st[b--];
		a/=2;
		b/=2;
	}
	s%=mod;
	return s;
}

void add(int i, ll v){
	v%=mod;
	for (i+=N;i;i/=2){
		st[i]+=v;
		while (st[i]>=mod) st[i]-=mod;
	}
}

vector<pair<int, int> > sps[1010101];
vector<pair<int, int> > eps[1010101];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for (int i=0;i<k;i++){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		sps[x1].push_back({y1, y2});
		eps[x2+1].push_back({y1, y2});
	}
	sps[n+1].push_back({1, m-1});
	set<pair<int, int> > has;
	for (int i=1;i<=n+1;i++){
		if (i==2) add(1, 1);
		sort(sps[i].rbegin(), sps[i].rend());
		for (int j=0;j<(int)sps[i].size();j++){
			if (!(j>0&&sps[i][j-1].F==sps[i][j].S+1)){
				auto it=has.lower_bound({sps[i][j].S+2, 0});
				int lo=1;
				if (it!=has.begin()){
					it--;
					lo=(*it).S+1;
				}
				ll v=sum(lo, sps[i][j].S);
				add(sps[i][j].S+1, v);
			}
			zero(1, 0, N-1, sps[i][j].F, sps[i][j].S);
		}
		for (auto e:eps[i]){
			has.erase(e);
		}
		for (auto s:sps[i]){
			has.insert(s);
		}
	}
	cout<<sum(1, m)<<endl;
}