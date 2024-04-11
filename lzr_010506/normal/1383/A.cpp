#include <bits/stdc++.h>
#define pcc pair<char, char>
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define X first
#define Y second
#define eps 1e-9
#define inf 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
#define ll long long
#define db double
using namespace std;
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
const int N = 1e6 + 10;

int n, cnt[26][26];
char s[N], t[N];
int main()
{
	int T = read();
	while(T --)
	{
		n = read();
		scanf("%s%s", s + 1, t + 1);
		rep0(i, 26) 
			rep0(j, 26)
				cnt[i][j] = 0;
		bool flag = 0;
		rep(i, 1, n)
		{
			cnt[s[i] - 'a'][t[i] - 'a'] = 1;
			if(s[i] > t[i])
			{
				puts("-1");
				flag = 1;
				break;
			}
		}
		
		int sum = 0;
		rep0(i, 26)
			rep(j, i + 1, 25)
				if(cnt[i][j])
				{
					sum ++;
					rep(k, j, 25) cnt[j][k] |= cnt[i][k];
					break;
				}
		if(!flag) cout << sum << endl;
	}
	return 0;
}