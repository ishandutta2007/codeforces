#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int h[101010];
int u[101010];
vector<int> g[101010];
int dp[101010];
int lol[101010];

int dfs(int x){
	if (u[x]) return 0;
	u[x]=1;
	int r=1;
	for (int nx:g[x]){
		r+=dfs(nx);
	}
	return r;
}

int n;

void go(int r, int x, int y){
	deque<pair<int, int> > ch;
	for (int i=r;i<=n;i+=x){
		if (dp[i]>0){
			pair<int, int> t={dp[i], i};
			while (ch.size()>0&&t.F<=ch.back().F+(i-ch.back().S)/x) ch.pop_back();
			ch.push_back(t);
		}
		while (ch.size()>0&&(i-ch.front().S)/x>y) ch.pop_front();
		if (ch.size()>0){
			if (dp[i]==0){
				dp[i]=ch.front().F+(i-ch.front().S)/x;
			}
			else {
				dp[i]=min(dp[i], ch.front().F+(i-ch.front().S)/x);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin>>n>>m;
	for (int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i=1;i<=n;i++){
		if (u[i]==0){
			h[dfs(i)]++;
		}
	}
	dp[0]=1;
	for (int k=1;k<=n;k++){
		if (h[k]){
			for (int i=0;i<k;i++){
				go(i, k, h[k]);
			}
		}
	}
	int v=n*2;
	for (int i=1;i<=n;i++){
		if (dp[i]>0){
			int x=i;
			int f=0;
			while (x){
				if (x%10!=4&&x%10!=7) f=1;
				x/=10;
			}
			if (!f){
				v=min(v, dp[i]-2);
			}
		}
	}
	if (v==n*2){
		cout<<-1<<endl;
	}
	else{
		cout<<v<<endl;
	}
}