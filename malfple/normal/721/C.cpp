#include <iostream>
#include <cstdio>

#include <algorithm>
#include <cstring>

#include <vector>
#include <string>
#include <queue>
#include <utility>

#define repp(i,a,b,d) for(int i=a; i<=b; i+=d)
#define rep(i,a,b) repp(i,a,b,1)
#define revv(i,a,b,d) for(int i=a; i>=b; i-=d)
#define rev(i,a,b) revv(i,a,b,1)

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

const ll OO = 2000000000;

int n,m;
int t;
vector<pair<int,int> >lst[5005];
bool vis[5005];
int dp[5005][5005];
int choice[5005][5005];

void filldp(int idx){
	if(idx == n)return;
	if(vis[idx])return;
	vis[idx] = true;
	
	rep(i,0,(int)lst[idx].size()-1){
		int target = lst[idx][i].ff;
		int cost = lst[idx][i].ss;
		filldp(target);
		rep(j,2,n){
			if(dp[target][j-1] > OO/2)continue;
			if(dp[target][j-1] + cost < dp[idx][j]){
				dp[idx][j] = dp[target][j-1] + cost;
				choice[idx][j] = target;
			}
		}
	}
}

int main(){
	scanf("%d %d %d",&n,&m,&t);
	rep(i,1,m){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		//scanf("%lld",&cost[a][b]);
		lst[a].pb(mp(b,c));
	}
	rep(i,1,n)rep(j,1,n)dp[i][j] = OO;
	dp[n][1] = 0;
	
	filldp(1);
	
	/*rep(i,1,n){
		rep(j,1,n)printf("%d ",dp[i][j]);
		printf("\n");
	}*/
	
	int ans = 0;
	rev(i,n,1){
		if(dp[1][i] <= t){
			ans = i;
			break;
		}
	}
	
	printf("%d\n",ans);
	int now = 1;
	while(ans){
		printf("%d ",now);
		now = choice[now][ans];
		ans--;
	}
	return 0;
}