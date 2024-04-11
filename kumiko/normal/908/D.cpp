//int!
#include <bits/stdc++.h>
using namespace std;
#define mkp make_pair
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)
#define all(a) a.begin(), a.end()
inline int ckmax(int &a, int b) { return a < b ? a = b, 1 : 0; }
inline int ckmin(int &a, int b) { return a > b ? a = b, 1 : 0; }
#define clean(a) memset(a, 0, sizeof(a))
typedef long long ll;
#define M 1000000007

int k, pa, pb;
int f[1005][1005];

int inv(int a){
	int b = M - 2, res = 1;
	for(; b; b >>= 1, a = (ll)a * a % M)
		if(b & 1) res = (ll)res * a % M;
	return res;
}

int main(){
	scanf("%d%d%d", &k, &pa, &pb);
	int p = (ll)pa * inv(pa + pb) % M;
	int q = (M - p + 1) % M;	
	for(int i = k - 1; i >= 0; --i){
		f[i][k] = (inv(q) + k - 1) % M;
		for(int j = k - 1; j >= 1; --j)
			f[i][j] = ((ll)p * f[i][j + 1] + (ll)q * (f[min(i + j, k)][j] + j)) % M;
		f[i][0] = f[i][1];
	}
	printf("%d\n", f[0][0]);
  return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                BUG
*/