//int!
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
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

const int xx[] = {0, 0, 1, -1};
const int yy[] = {1, -1, 0, 0};

int p[4];
int  n, m;
char mp[55][55];
char s[107];
int Sx, Sy;

bool ok(int x, int y){
	return x >= 1 && x <= n && y >= 1 && y <= m && mp[x][y] != '#';
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%s", mp[i] + 1);
		for(int j = 1; j <= m; ++j)
			if(mp[i][j] == 'S') Sx = i, Sy = j;
	}
	scanf("%s", s);
	for(int i = 0; i < 4; ++i) p[i] = i;
	int ans = 0;
	do{
		int x = Sx, y = Sy;
		bool flag = 1;
		for(int i = 0; s[i]; ++i){
			x += xx[p[s[i] - '0']];
			y += yy[p[s[i] - '0']];
			if(!ok(x, y)) flag = 0;
			else if(mp[x][y] == 'E') break;
		}
		if(flag && mp[x][y] == 'E') ++ans;
	}while(next_permutation(p, p + 4));
	printf("%d\n", ans);
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