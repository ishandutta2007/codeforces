#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X Fstst
#define Y second
#define pcc pair<char, char>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
const int P = 29;
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int MA = 10, ML = 300;
struct Node
{
    int Fst[MA],Las[MA];
    int len;
    bool Sub[1<<MA];
    Node();
};
int n,m;
Node s[ML];
Node::Node()
{
    memset(Fst, 0, sizeof(Fst));
    memset(Las, 0, sizeof(Las));
    len = 0;
    memset(Sub, 0, sizeof(Sub));
}
Node operator + (Node a,Node b)
{
    Node c;
    c.len = min(a.len + b.len, MA - 1);
    rep(i, 1, a.len)
        c.Fst[i] = a.Fst[i];
    rep(i, 1, c.len - a.len)
        c.Fst[a.len + i] = b.Fst[i];
    rep(i, 1, b.len)
        c.Las[i] = b.Las[i];
    rep(i, 1, c.len - b.len)
        c.Las[b.len + i] = a.Las[i];

   	rep(i, 0, (1 << MA) - 1)
        c.Sub[i] = a.Sub[i] || b.Sub[i];

    rep(i, MA - b.len, a.len)
    {
        int v = 1, s = 0;
        rrep(j, i, 1)
        {
            s += v * a.Las[j];
            v <<= 1;
        }
        rep(j, 1, MA - i)
        {
            s += v * b.Fst[j];
            v <<= 1;
        }
        c.Sub[s] = 1;
    }
    return c;
}
Node read_Node()
{
    char ch[ML];
    Node a;
    int l;
    scanf("%s", ch + 1);
    l=strlen(ch+1);
    a.len=min(l,MA-1);
    rep(i, 1, a.len)
    {
        a.Fst[i]=ch[i]-'0';
        a.Las[i]=ch[l+1-i]-'0';
    }

    rep(i, 1, l - MA + 1)
    {
        int v=1,s=0;
        rep(j, i, i + MA - 1)
        {
            s+=v*(ch[j]-'0');
            v*=2;
        }
        a.Sub[s]=true;
    }
    return a;
}
bool Check(Node a,int k)
{
    bool Sub[1 << MA];
    memset(Sub,0,sizeof(Sub));
    rep(i, 0, (1 << MA) - 1)
        Sub[i&((1<<k)-1)]|=a.Sub[i];

    rep(i, k, a.len)
    {
        int v=1,s=0;

        for(int j = i; j > i - k; j --)
        {
            s += v * a.Las[j];
            v <<= 1;
        }
        Sub[s] = 1;
    }
    rep(i, 0, (1 << k) - 1)
        if(!Sub[i])
            return false;
    return true;
}
int Query(Node a)
{
    int res = 0;
    while(res + 1 <= MA && Check(a, res + 1)) res ++;
    return res;
}

int main()
{
	n = read();
	rep(i, 1, n)
        s[i] = read_Node();
    m = read();
    rep(i, n + 1, n + m)
    {
        int a,b;
        a = read();
        b = read();
        s[i] = s[a] + s[b];
        printf("%d\n", Query(s[i]));
    }
    return 0;
}