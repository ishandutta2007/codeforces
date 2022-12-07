#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define sec second
#define ll long long
#define pll pair<ll, ll>
using namespace std;
int n, m, tot, w[100010];
string ch;
map<string, int> v;
pll Ve[300010];
vector<int> Map[300010];
queue<int> Q;

void Make(string &ch)
{
    int len = ch.size(), cnt = 0;
    for(int j = 0; j < len; j ++)
    {
        if(ch[j] >= 'A' && ch[j] <= 'Z') ch[j] = ch[j] - 'A' + 'a';
        if(ch[j] == 'r') cnt ++;
    }
    if(!v.count(ch))
    {
        v[ch] = tot;
        Ve[tot ++] = mp(cnt, len);
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> ch;
        Make(ch);
        w[i] = v[ch];
    }
    cin >> m;
    for(int i = 0; i < m; i ++)
    {
        string s, t;
        cin >> s >> t;
        Make(s);
        Make(t);
        Map[v[t]].pb(v[s]);
    }

    while(!Q.empty()) Q.pop();
    for(int i = 0; i < tot; i ++)
        Q.push(i);
    while(!Q.empty())
    {
        int Now = Q.front();
        pll u = Ve[Now];
        Q.pop();
        int Len = Map[Now].size();
        for(int i = 0; i < Len; i ++)
        {
            int To = Map[Now][i];
            if(Ve[To] > u)
            {
                Ve[To] = u;
                Q.push(To);
            }
        }
    }

    ll Ans1 = 0, Ans2 = 0;
    for(int i = 0; i < n; i ++)
    {
        Ans1 += Ve[w[i]].fst;
        Ans2 += Ve[w[i]].sec;
    }
    cout << Ans1 << " " << Ans2;
    return 0;
}