#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <time.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()

int n, m;
char ch[100020];
int d[2020][2020];
const int MOD = 1e9 + 7;

int main(){
	scanf("%d%d", &n, &m);
	scanf("%s", ch);
	int L = 0, R = 0;
	for(int i=0;i<m;i++){
		if(ch[i] == '(')++R;
		else{
			if(R)R--;
			else L++;
		}
	}
	d[0][0] = 1;
	for(int i=1;i<=2000;i++){
		for(int j=0;j<=i;j++){
			d[i][j] = (j == 0 ? 0 : d[i-1][j-1]) + d[i-1][j+1];
			d[i][j] %= MOD;
		}
	}
	ll ans = 0;
	for(int i=0;i<=n-m;i++){
		//i, n-m-i;
		for(int j=L;j<=i;j++){
			if(j-L+R > n-m-i)break;
			ans += (ll)d[i][j] * d[n-m-i][j-L+R];
			ans %= MOD;
		}
	}
	printf("%lld", ans);
	return 0;
}