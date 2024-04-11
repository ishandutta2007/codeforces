#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

set<int> g[202020];

int a[202020];
int r[202020];

int dp[202020];

void dfs1(int x, int p){
	for (int nx:g[x]){
		if (nx!=p){
			dfs1(nx, x);
			dp[x]=max(dp[x], dp[nx]+1);
		}
	}
}

pair<int, int> ma={0, 0};

void dfs2(int x, int p, int pl){
	ma=max(ma, {max(pl, dp[x]), -x});
	pair<int, int> m1={pl, 0};
	pair<int, int> m2={-1, 0};
	for (int nx:g[x]){
		if (nx!=p){
			if (dp[nx]+1>m1.F){
				m2=m1;
				m1={dp[nx]+1, nx};
			}
			else if(dp[nx]+1>m2.F){
				m2={dp[nx]+1, nx};
			}
		}
	}
	for (int nx:g[x]){
		if (nx!=p){
			if (nx==m1.S){
				dfs2(nx, x, m2.F+1);
			}
			else{
				dfs2(nx, x, m1.F+1);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=0;i<n-1;i++){
		int aa,bb;
		cin>>aa>>bb;
		g[aa].insert(bb);
		g[bb].insert(aa);
	}
	for (int i=0;i<m;i++){
		int t;
		cin>>t;
		a[t]=1;
		if (m==1){
			cout<<t<<endl<<0<<endl;
			return 0;
		}
	}
	queue<int> rm;
	for (int i=1;i<=n;i++){
		if (g[i].size()==1&&a[i]==0){
			rm.push(i);
		}
	}
	int ss=n;
	while (!rm.empty()){
		int x=rm.front();
		rm.pop();
		r[x]=1;
		//cout<<x<<endl;
		ss--;
		for (int nx:g[x]){
			g[nx].erase(x);
			if (g[nx].size()==1&&a[nx]==0){
				rm.push(nx);
			}
		}
		g[x].clear();
	}
	for (int i=1;i<=n;i++){
		if (r[i]==0){
			dfs1(i, 0);
			dfs2(i, 0, 0);
			cout<<-ma.S<<endl<<2*(ss-1)-ma.F<<endl;
			return 0;
		}
	}
}