#include<bits/stdc++.h>
#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define mpr make_pair
#define x(v) (v).first
#define y(v) (v).second
#define siz(v) (int)(v).size()
#define pb push_back
using namespace std;
const int N = 1e5 + 10;
typedef pair<int, int> pii;
typedef long long ll;
typedef double db;
int t;
char a[N], b[N];
int cnt[26][26], vis[26]; 
int main()
{
	scanf("%d", &t);
	rep(amo, 1, t)
	{
		int n;
		scanf("%d", &n);
		scanf("%s", a + 1);
		int flag = 0;
		scanf("%s", b + 1);
		rep(i, 1, n) if(a[i] > b[i]) flag = 1;
		if(flag) 
		{
			printf("-1\n");
			continue;
		}
		rep(i, 0, 25) rep(j, 0, 25) cnt[i][j] = 0;
		rep(i, 1, n) cnt[a[i] - 'a'][b[i] - 'a']++;
		int ans = 0;
		rep(i, 0, 25)
		{
			rep(j, 0, 25) vis[j] = 0;
			cnt[i][i] = 0;
			rep(j, 0, i - 1)
			{
				if(cnt[j][i]) vis[j] = 1, ans++ , cnt[j][i] = 0;
			}
			rep(j, 0, 25) 
			{
				if(!vis[j]) continue;
				rep(k, 0, 25) cnt[i][k] += cnt[j][k], cnt[j][k] = 0;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}