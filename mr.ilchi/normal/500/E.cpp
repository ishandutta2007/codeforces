#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000+10;

int n;
int p[MAXN],l[MAXN];
pair<int,int> f[MAXN];

struct node{
	int who,cost;
	node () {}
	node (int who, int cost) : who(who), cost(cost) {}
}dp[MAXN][20];

int main(){
	scanf("%d", &n);
	for (int i=0; i<n; i++)
		scanf("%d%d", &p[i], &l[i]);
	stack<int> s;
	for (int i=n-1; i>=0; i--){
		f[i] = pair<int,int>(i,p[i]+l[i]);
		while (!s.empty()){
			if (p[s.top()] <= p[i] + l[i]){
				f[i].first = f[s.top()].first;
				f[i].second= max(f[i].second, f[s.top()].second);
				s.pop();
			}else
				break;
		}
		s.push(i);
	}
	int MAXP = 0;
	for (int k=0; (1<<k)<=n; k++){
		for (int i=0; i<n; i++){
			if (k == 0){
				if (f[i].first == n-1)
					dp[i][k] = node(i,0); 
				else
					dp[i][k] = node(f[i].first+1, p[f[i].first+1] - f[i].second);
			}else{
				dp[i][k] = dp[i][k-1];
				if (f[dp[i][k].who].first != n-1){
					dp[i][k].who = dp[dp[i][k-1].who][k-1].who;
					dp[i][k].cost+= dp[dp[i][k-1].who][k-1].cost;
				}
			}
		}
		MAXP = k;
	}
	int que; scanf("%d", &que);
	for (int o=0; o<que; o++){
		int x,y; scanf("%d%d", &x, &y);
		x--; y--;
		int ans = 0;
		for (int k=MAXP; k>=0; k--) if (f[dp[x][k].who].first < y){
			ans+= dp[x][k].cost;
			x = dp[x][k].who;
		}
		if (f[x].first < y)
			ans+= dp[x][0].cost;
		printf("%d\n", ans);
	}
	return 0;
}