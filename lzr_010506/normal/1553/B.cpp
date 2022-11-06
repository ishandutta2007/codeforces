#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
inline ll read1()
{
    ll x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

int T;
string s1, s2;

int main() 
{
	int T = read();
	while(T --)
	{
		cin >> s1 >> s2;
		bool ans = 0; 
		int l = s2.size();
		rep0(i, l)
		{
			string p1 = s2.substr(0 , i + 1) , p2 = s2.substr(i , l - i);
			reverse(p2.begin() , p2.end());

			if (s1.find(p1) == s1.npos || s1.find(p2) == s1.npos) continue;

			reverse(p1.begin() , p1.end());
			reverse(p2.begin() , p2.end());
			int tl = min(p1.size() , p2.size()); 
			bool ok = 1;
			rep0(j, tl) ok &= (p1[j] == p2[j]);

			ans |= ok ;
		}

		if (ans) printf("YES\n") ;
		else printf("NO\n") ;
	}

	return 0 ;
}