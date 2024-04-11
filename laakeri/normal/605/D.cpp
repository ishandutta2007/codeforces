#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

const int N=1<<19;
pair<int, int> st[2*N];
int a[101010];
int b[101010];
int c[101010];
int d[101010];

set<pair<int, int> > lol[2*N];

void addmax(int i, pair<int, int> v){
	lol[i].insert(v);
	st[i+N]=(*lol[i].rbegin());
	for (i=(i+N)/2;i;i/=2){
		st[i]=max(st[i*2], st[i*2+1]);
	}
}

void rmmax(int i, pair<int ,int> v){
	lol[i].erase(v);
	if ((int)lol[i].size()>0){
		st[i+N]=(*lol[i].rbegin());
	}
	else{
		st[i+N]={0, 0};
	}
	for (i=(i+N)/2;i;i/=2){
		st[i]=max(st[i*2], st[i*2+1]);
	}
}

pair<int, int> getmax(int a, int b){
	a+=N;
	b+=N;
	pair<int, int> r={0, 0};
	while (a<=b){
		if (a%2) r=max(r, st[a++]);
		if (!(b%2)) r=max(r, st[b--]);
		a/=2;
		b/=2;
	}
	return r;
}

int di[101010];
int f[101010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> cc;
	int n;
	cin>>n;
	cc.push_back(0);
	for (int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i]>>d[i];
		cc.push_back(a[i]);
		cc.push_back(b[i]);
		cc.push_back(c[i]);
		cc.push_back(d[i]);
	}
	sort(cc.begin(), cc.end());
	cc.erase(unique(cc.begin(), cc.end()), cc.end());
	for (int i=1;i<=n;i++){
		a[i]=lower_bound(cc.begin(), cc.end(), a[i])-cc.begin();
		b[i]=lower_bound(cc.begin(), cc.end(), b[i])-cc.begin();
		c[i]=lower_bound(cc.begin(), cc.end(), c[i])-cc.begin();
		d[i]=lower_bound(cc.begin(), cc.end(), d[i])-cc.begin();
		
		if (i<n) addmax(c[i], {d[i], i});
	}
	queue<int> bfs;
	bfs.push(n);
	int v=n+2;
	int vv=0;
	while (!bfs.empty()){
		int x=bfs.front();
		bfs.pop();
		if (a[x]==0&&b[x]==0){
			v=di[x];
			vv=x;
			break;
		}
		else{
			while (1){
				auto asd=getmax(a[x], N-1);
				if (asd.F>=b[x]&&asd.S>0){
					rmmax(c[asd.S], {d[asd.S], asd.S});
					di[asd.S]=di[x]+1;
					bfs.push(asd.S);
					f[asd.S]=x;
				}
				else{
					break;
				}
			}
		}
	}
	if (v==n+2){
		cout<<-1<<endl;
	}
	else{
		cout<<v+1<<endl;
		while (1){
			cout<<vv<<" ";
			if (vv==n) break;
			vv=f[vv];
		}
		cout<<endl;
	}
}