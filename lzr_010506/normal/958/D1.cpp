#include <bits/stdc++.h>
#define rep(i,  x,  y) for(int i = x; i <= y; i ++)
#define rrep(i, x,  y) for(int i = x; i >= y; i --)
#define ll long long
//#define X fisrt
#define Y second
#define pb push_back
//#define mp make_pair
#define ls rt << 1
#define rs rt << 1 | 1
#define INF 0x3f3f3f3f
#define pll pair<ll, ll>
#define db double
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
using namespace std;

char ch[110];
int n, X[200010], Y[200010];
map<int, int> mp[200010];

int gcd(int a, int b)
{
    while(a)
    {
        int c = a;
        a = b % a;
        b = c;
    }
    return b;
}

int main()
{
	n = read();
	rep(i, 1, n)
	{
		scanf("%s", ch + 1);
		int t = 2;
		ll now = 0;
        while(1)
        {
            now = now * 10 + ch[t] - '0';
            t ++;
            if(ch[t] == '+')break;
        }
        t ++;
        X[i] = now;
        now = 0;
        while(1)
        {
            now = now * 10 + ch[t] - '0';
            t ++;
            if(ch[t] == ')')break;
        }
        t ++;
        t ++;
        X[i] += now;
        now = 0;
        while(1)
        {
            now = now * 10 + ch[t] - '0';
            t ++;
            if(ch[t] < '0' || ch[t] > '9')break;
        }
        Y[i] = now;
        ll GCD = gcd(X[i], Y[i]);
        X[i] /= GCD;
        Y[i] /= GCD;
        mp[X[i]][Y[i]] ++;
	}
	rep(i, 1, n)
		cout << mp[X[i]][Y[i]] << " ";
	return 0;
}