#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int is[202020];
int aps[202020];
vector<int> g[202020];

ll v=0;

void dfs(int x, int p, int d){
	v+=(ll)d*(ll)is[x];
	aps[x]+=is[x];
	for (int nx:g[x]){
		if (nx!=p){
			dfs(nx, x, d+1);
			aps[x]+=aps[nx];
		}
	}
}

void go(int x, int p, int d, int t){
	vector<pair<int, int> > lol;
	if (is[x]) lol.push_back({1, x});
	int su=is[x];
	for (int nx:g[x]){
		if (nx!=p){
			su+=aps[nx];
			lol.push_back({aps[nx], nx});
		}
	}
	if (lol.size()==0) return;
	sort(lol.rbegin(), lol.rend());
	lol[0].F-=t;
	if (lol[0].F*2<=su-t){
		v-=(ll)d*(su-t);
		for (int nx:g[x]){
			if (nx!=p){
				go(nx, x, d+1, aps[nx]);
			}
		}
	}
	else{
		int tm=(su-t-lol[0].F);
		v-=(ll)d*tm*2;
		go(lol[0].S, x, d+1, t+tm);
		for (int nx:g[x]){
			if (nx!=p&&nx!=lol[0].S){
				go(nx, x, d+1, aps[nx]);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	for (int i=0;i<2*k;i++){
		int a;
		cin>>a;
		is[a]++;
	}
	for (int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 0, 0);
	go(1, 0, 0, 0);
	cout<<v<<endl;
}