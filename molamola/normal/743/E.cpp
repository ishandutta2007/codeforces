#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;
typedef long long ll;
typedef pair<int,int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

int n, p[1010];
int pre[1010][1010];

void solve(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++)scanf("%d", p+i);
	int ord[9] = {};
	rep(i, 8)ord[i + 1] = i + 1;
	int o[9] = {};
	for(int i=1;i<=n;i++)pre[i][0] = i;
	for(int i=1;i<=n;i++){
		pre[i][1] = o[p[i]];
		o[p[i]] = i;
	}
	for(int j=2;j<=n;j++){
		for(int i=1;i<=n;i++)pre[i][j] = pre[ pre[i][j-1] ][1];
	}
	int pv[1010][9] = {};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=8;j++)pv[i][j] = pv[i-1][j];
		pv[i][p[i]] = i;
	}
	int ans = 0;
	for(int i=1;i<=8;i++)ans += !!o[i];
	do{
		int low = 8, high = n, res = 0;
		while(low <= high){
			int mid = (low + high) >> 1;
			int a = mid / 8;
			int ok = 0;
			for(int i=0;i<1<<8;i++){
				if(__builtin_popcount(i) != mid - 8*a)continue;
				int x = pv[n][ord[8]];
				for(int j=0;j<8;j++){
					int y = a; if(1<<j & i)++y;
					if(pre[x][y-1] == 0)break;
					if(j == 7)ok = 1;
					x = pre[x][y-1] - 1;
					x = pv[x][ord[7-j]];
				}
				if(ok)break;
			}
			if(ok)res = mid, low = mid + 1;
			else high = mid - 1;
		}
		ans = max(ans, res);
	}while(next_permutation(ord + 1, ord+9));
	printf("%d\n", ans);
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}