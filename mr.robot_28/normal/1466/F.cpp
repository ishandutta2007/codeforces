#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)a.size()

using namespace std;
#define int long long
int n;
const int N = 5e5;
int x[N];
const int mod = 1e9 + 7;
void relax(int &a)
{
    if(a >= mod)
    {
        a -= mod;
    }
    if(a < 0)
    {
        a += mod;
    }
}
map <int, int> mp;
int used[N];
int used2[N];
bool used1[N];
int dsu[N], rang[N];
int comp[N];
int pred(int a)
{
    if(a == dsu[a]) return a;
    return dsu[a] = pred(dsu[a]);
}
void unite(int a, int b)
{
    a = pred(a);
    b = pred(b);
    if(rang[a] < rang[b])
    {
        swap(a, b);
    }
    comp[a] = (comp[a] | comp[b]);
    dsu[b] = a;
    rang[a] += rang[b];
}
signed main() {
//    ios_base::sync_with_stdio(0);
  //  cin.tie(0);
    //cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i< N; i++)
    {
        dsu[i] = i;
        rang[i] = 1;
        comp[i] = 0;
        used[i] = 0;
        used1[i] = 0;
        used2[i] = 1;
    }
    vector <vector <int> > x(n);
    for(int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        x[i].resize(k);
        for(int j = 0; j< k; j++)
        {
            cin >> x[i][j];
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(x[i].size() == 1)
        {
            x[i][0]--;
            if(comp[pred(x[i][0])])
            {
                used2[i] = 0;
            }
            else
            {
                comp[pred(x[i][0])] = 1;
            }
            continue;
        }
        x[i][0]--;
        x[i][1]--;
        used1[x[i][0]] = used1[x[i][1]] = 1;
        int a = pred(x[i][0]);
        int b = pred(x[i][1]);
        if(a == b || comp[a] && comp[b])
        {
            used2[i] = 0;
            continue;
        }
        unite(x[i][0], x[i][1]);
    }
    vector <int> ansp;
    int ans = 1;
    for(int i = 0; i < n; i++)
    {
        if(used2[i])
        {
            ansp.push_back(i + 1);
            ans = ans * 2 % mod;
        }
    }
    cout <<ans << " " << ansp.size() << "\n";
    for(int i = 0; i < ansp.size(); i++)
    {
        cout << ansp[i] << " ";
    }
    return 0;
}