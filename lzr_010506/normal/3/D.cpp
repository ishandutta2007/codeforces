#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ls rt << 1
#define rs rt << 1 | 1
#define mod 1000000007
#define sz(x) (int)(x).size()
#define vi vector<int>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 5e4 + 10;
char s[N];
int a[N][2], m, num, k, f[N], len;
bool Left[N], flag = 1;
struct Node
{
    int id, v;
    Node(int _id = -1, int _v = -1)
    {
        id = _id;
        v = _v;
    }
    friend bool operator < (Node a,Node b)
    {
        return a.v < b.v;
    }
};
priority_queue<Node> q;
int main()
{
    scanf("%s", s);
    len = strlen(s);
    rep(i, 0, len - 1)
        if(s[i] == '?') f[i] = m ++;
    rep(i, 0, m - 1)
        scanf("%d%d", &a[i][0], &a[i][1]);
    rep(i, 0, len - 1)
    {
        if(s[i] == '(') num ++;
        else if(s[i] == ')') num --;
        else if(s[i] == '?')
        {
            num --;
            q.push(Node(i, a[f[i]][1] - a[f[i]][0]));
        }
        if(num < 0)
        {
            if(q.empty())
            {
                flag = 0;
                break;
            }
            else
            {
                Node t = q.top();
                q.pop();
                Left[t.id] = 1;
                num += 2;
            }
        }
    }
    if(flag && num == 0)
    {
        ll ans = 0;
        rep(i, 0, len - 1)
            if(s[i] == '?')
            {
                if(Left[i]) ans += a[f[i]][0], s[i] = '(';
                else ans += a[f[i]][1], s[i] = ')';
        	}
        printf("%I64d\n%s",ans,s);
    }
    else printf("-1");
    return 0;
}