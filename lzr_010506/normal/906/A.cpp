#include <bits/stdc++.h>
#define rep(i,  x,  y) for(int i = x; i <= y; i ++)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ls rt << 1
#define rs rt << 1 | 1
#define INF 0x3f3f3f3f
#define mod 1000000007
using namespace std;

int n;
bitset<26> b;
char ch[100010], op[10];

int main()
{
	scanf("%d", &n);
    int ans = 0;
    rep(i, 1, n)
    {
        scanf("%s%s", op, ch);
        bitset<26> t;
        t.reset();
        if (op[0] == '!')
        {
            if (b.count() >= 25) ans ++;
            int len = (int) strlen(ch);
            rep(j, 0, len - 1) t[ch[j] - 'a'] = 1;
            t.flip();
            b = b | t;
        }
        else
        	if (op[0] == '.')
	        {
	            int len = (int) strlen(ch);
	            rep(j, 0, len - 1) t[ch[j] - 'a'] = 1;
	            b = b | t;
	        }
	        else
	        {
            	if (b.count() >= 25 && b[ch[0] - 'a']) ans ++;
            	b[ch[0] - 'a'] = 1;
        	}
    }
    printf("%d\n", ans);
    return 0;
}