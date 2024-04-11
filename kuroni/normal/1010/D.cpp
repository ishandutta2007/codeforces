#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1000005;

string s[N];
int n, ch[N][2], t[N], a[N], ans[N][2];

void calc(int u, int &ret)
{
    if (s[u] == "AND")
        ret = a[ch[u][0]] & a[ch[u][1]];
    else if (s[u] == "OR")
        ret = a[ch[u][0]] | a[ch[u][1]];
    else if (s[u] == "XOR")
        ret = a[ch[u][0]] ^ a[ch[u][1]];
    else if (s[u] == "NOT")
        ret = a[ch[u][0]] ^ 1;
}

void DFS_1(int u)
{
    if (u == 0)
        return;
    DFS_1(ch[u][0]);
    DFS_1(ch[u][1]);
    calc(u, a[u]);
}

void DFS_2(int u, int p = 0)
{
    if (u == 0)
        return;
    if (u == 1)
    {
        ans[1][0] = 0;
        ans[1][1] = 1;
    }
    else
    {
        ans[u][a[u]] = a[1];
        a[u] ^= 1;
        int tmp;
        calc(p, tmp);
        ans[u][a[u]] = ans[p][tmp];
        a[u] ^= 1;
    }
    DFS_2(ch[u][0], u);
    DFS_2(ch[u][1], u);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i] >> ch[i][0];
        if (s[i] == "AND" || s[i] == "OR" || s[i] == "XOR")
            cin >> ch[i][1];
        else if (s[i] == "IN")
            swap(a[i], ch[i][0]);
    }
    DFS_1(1);
    DFS_2(1);
    for (int i = 1; i <= n; i++)
        if (s[i] == "IN")
            cout << ans[i][a[i] ^ 1];
}