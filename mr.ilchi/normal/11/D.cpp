/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>

using namespace std;

typedef long long ll;

const int MAXN= 19+1;
const int MAXL= (1<<19)+5;

bool mark[MAXN];
bool adj[MAXN][MAXN];
int n, e;
int test[MAXN];
ll dp[MAXL][MAXN];

int main (){
	cin >> n >> e;
	for (int i=1 ;i<=e ;i++){
		int x,y;
		cin >> x >> y;
		adj[x][y]= adj[y][x]= true;
	}
	ll res= 0;
	for (int i=1,leni=(1<<n);i< leni;i ++){
		int p=1;
		while (mark[p])
			mark[p++]= false;
		mark[p]=true;
		int len= 0;
		test[len++]= p;
		for (int j=p+1;j<= n;j ++){
			if (mark[j])
				test[len++]= j;
		}
		if (len==1){
			dp[i][p]= 1;
			continue;
		}
		if (len== 2){
			dp[i][test[1]]= adj[p][test[1]];
			continue;
		}
		for (int j=1;j< len;j ++){
			int tmp= test[j];
			int cur= (1<<(tmp-1));
			for (int z= 1;z<len;z ++)
				if (adj[tmp][test[z]])
					dp[i][tmp]+= dp[i^cur][test[z]];
			res+= dp[i][tmp] * adj[tmp][p];
		}
	}
	cout << res/2 << endl;

	return 0;
}