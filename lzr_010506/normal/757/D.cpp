#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define REP(i,j,k)  for(int i=(j);i<=(k);++i)

const int N = 20;
const int mod = 1e9+7;

int f[80][(1<<N)+10];
char st[80];
int n;

void add(int &x,int y)
{
	x += y;
	if(x >= mod) x -= mod;
}

int main()
{
	scanf("%d", &n);
	scanf("%s", st);
	REP(i, 0, n)
	{
		f[i][0] = 1;
		REP(j, 0, (1 << N) - 1)
		{
			if(!f[i][j]) continue;
			int t = 0;
			REP(k, i, n - 1)
			{
				t = t << 1 | (st[k] - '0');
				if(t > N) break;
				if(t) add(f[k + 1][(1 << (t - 1)) | j], f[i][j]);
			}
		}
	}
	int ans = 0;
	REP(i, 0, n)
	{
		int t = 1;
		while(t < (1 << N))
		{
			add(ans, f[i][t]);
			t = t << 1 | 1;
		}
	}
	cout << ans << endl;

	return 0;
}