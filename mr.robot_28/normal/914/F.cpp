#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
const int N = 2e5;
string s;
int z[N];
const int T = 320;
struct node{
    int next[26];
    int link;
    int cnt;
    int len;
    node(){
        link = 0;
        for(int i = 0; i < 26;i++)
        {
            next[i] = -1;
        }
        cnt = len = 0;
    };
};
node mass[T][T * 2];
string cur;
int sz, last;
void init(int ind)
{
    for(int i = 0; i < T * 2; i++)
    {
        mass[ind][i] = node();
    }
    mass[ind][0].len = 0;
    mass[ind][0].link = -1;
    sz = 1;
    last = 0;
}
void extend(int ind, char cc, int which)
{
    int c = cc - 'a';
    int cur = sz++;
    mass[ind][cur].len = mass[ind][last].len + 1;
    int p = last;
    for(;p != -1 && mass[ind][p].next[c] == -1; p = mass[ind][p].link)
    {
        mass[ind][p].next[c] = cur;
    }
    if(p == -1)
    {
        mass[ind][cur].link = 0;
    }
    else
    {
        int q = mass[ind][p].next[c];
        if(mass[ind][q].len == mass[ind][p].len + 1)
        {
            mass[ind][cur].link = q;
        }
        else
        {
            int clone = sz++;
           // mass[ind][clone].next = mass[ind][q].next;
            for(int j = 0; j < 26; j++)
            {
                mass[ind][clone].next[j] = mass[ind][q].next[j];
            }
            mass[ind][clone].link = mass[ind][q].link;
            mass[ind][clone].len = mass[ind][p].len + 1;
            for(; p != -1 && mass[ind][p].next[c] == q; p = mass[ind][p].link)
            {
                mass[ind][p].next[c] = clone;
            }
            mass[ind][q].link = mass[ind][cur].link = clone;
        }
    }
    mass[ind][cur].cnt = 1;
    last = cur;
}
vector <int> g[N];
void dfs(int ind, int v)
{
    for(auto to : g[v])
    {
        dfs(ind, to);
        mass[ind][v].cnt += mass[ind][to].cnt;
    }
}
void rebuild(int l, int r)
{
    init(l / T);
    for(int i = l; i <= r; i++)
    {
        extend(l / T, s[i], i);
    }
    assert(sz < T * 2);
    for(int i = 0; i < sz; i++)
    {
        g[i].clear();
    }
    for(int i = 0; i  < sz; i++)
    {
        if(mass[l / T][i].link != -1)
        {
            g[mass[l / T][i].link].push_back(i);
        }
    }
    dfs(l / T, 0);
}
int go_to(int ind, int v, int i)
{
    if(v == -1)
    {
        return 0;
    }
    if(i == sz(cur))
    {
        return mass[ind][v].cnt;
    }
    return go_to(ind, mass[ind][v].next[cur[i] - 'a'], i + 1);
}
char s1[N];
int ans_query1(int l, int r)
{
    int it = 0;
    for(int i = 0; i < sz(cur); i++)
    {
        s1[it++] = cur[i];
    }
    s1[it++] = '#';
    for(int i = l; i <= r; i++)
    {
        s1[it++] = s[i];
    }
    l = 0, r = -1;
    int ans = 0;
    for(int i = 1; i < it; i++)
    {
        if(i > r)
        {
            int k = 0;
            while(k + i < it && s1[k] == s1[k + i])
            {
                k++;
            }
            z[i] = k;
            if(k != 0)
            {
                l = i;
                r = i + k - 1;
            }
        }
        else if(z[i - l] + i <= r)
        {
           // cout << "A ";
            z[i] = z[i - l];
        }
        else
        {
            int d = r - i;
            while(d + i < it && s1[d] == s1[d + i])
            {
                d++;
            }
            z[i] = d;
            if(d + i - 1 > r)
            {
                r = i + d - 1;
                l = i;
            }
        }
        if(z[i] >= sz(cur))
        {
            ans++;
        }
  //      cout << z[i] << " ";
    }
    //cout << "\n";
    return ans;
}
int st = 0;
int ans_query2(int l, int r)
{
    if(r - l <= 3 * T)
    {
        return ans_query1(l, r);
    }
  //  cout << "A " << st << "\n";
    int s = 0;
    if(l % T != 0)
    {
        s += ans_query1(l, l + T - l % T + sz(cur) - 2);
        l += T - l % T;
    }
    if(r % T != T - 1)
    {
        s += ans_query1(r - r % T - (sz(cur) - 1), r);
        r -= r % T + 1;
    }
    while(l + T < r)
    {
        s += go_to(l / T, 0, 0);
        s += ans_query1(l + T - sz(cur) + 1, l + T + sz(cur) - 2);
        l += T;
    }
    s += go_to(l / T, 0, 0);
    return s;
}
signed main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  	cout.tie(NULL);
  	cin >> s;
  	for(int i = 0; i < sz(s); i += T)
    {
        int r = min(sz(s), i + T) - 1;
        rebuild(i, r);
    }
  	int q;
  	cin >> q;
  //	int st = 0;
  	while(q--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int i;
            cin >> i;
            char c;
            cin >> c;
            i--;
            s[i] = c;
            int i1 = i / T;
            rebuild(i1 * T, min((i1 + 1) * T - 1, sz(s) - 1));
        }
        else{
            int l, r;
            cin >> l>> r;
            l--;
            r--;
            cin >> cur;
            if(sz(cur) >= T)
            {
                cout << ans_query1(l, r) << "\n";
            }
        /*    else if(sz(s) >= 100)
            {
                cout << 0 << "\n";
            }*/
            else
            {
                //cout << 0 << "\n";
                cout << ans_query2(l, r) << "\n";
            }
        }
        st++;
    }
    return 0;
}