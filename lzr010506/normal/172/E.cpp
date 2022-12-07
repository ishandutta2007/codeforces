#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define ll long long
#define FOR(i, x, y) for(int (i) = (x); (i) <= (y); (i) ++)
using namespace std;

int n, head[1000010], to[1000010], nxt[1000010], St[1000010], cnt;
char str[1000010];
string v[1000010];

void add(int a, int b)
{
    to[cnt] = b;
    nxt[cnt] = head[a];
    head[a] = cnt ++;
}

int dfs(int u, int pos, vector<string> &ch)
{
    int res = 0;
    if(pos == ch.size() - 2 && ch[pos + 1] == v[u]) res = 1;
    if(pos < (int)ch.size() - 2 && ch[pos + 1] == v[u]) pos ++;
    for(int i = head[u]; ~i; i = nxt[i])
        res += dfs(to[i], pos, ch);
    return res;
}

int main()
{
    scanf("%s", str);
    memset(head, -1, sizeof(head));
    vector< pair<string, bool> > ss;
    memset(head, -1, sizeof(head));
    for(int i = 0; str[i]; i ++)
    {
        string s;
        int t = i + 1;
        bool flag = 0;
        if(str[t] == '/') t ++, flag = 1;
        while(str[t] != '/' && str[t] != '>') s += str[t ++];
        ss.pb( mp(s, flag) );
        if(str[t] == '/') ss.pb( mp(s, 1) ), t ++;
        i = t;
    }
    int top = 0;
    for(int i = 0; i < ss.size(); i ++)
        if(!ss[i].second)
        {
            St[++ top] = ++ n;
            v[n] = ss[i].first;
            add(St[top - 1], n);
        }
        else top --;
    int m;
    vector<string> ch;
    scanf("%d", &m);
    gets(str);
    while(m --)
    {
        ch.clear();
        gets(str);
        int l = strlen(str);
        for(int i = 0; i < l; i ++)
        {
            int t = i;
            string s;
            while(t < l && str[t] != ' ') s += str[t ++];
            i = t;
            ch.pb(s);
        }
        printf("%d\n", dfs(0, -1, ch));
    }
    return 0;
}