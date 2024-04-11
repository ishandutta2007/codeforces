#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
using namespace std;
string s;
const int N = 1e5;
int a[N];
int b[N];
int it = 0;
bool fl;
void go_to(int l, int r)
{
    if(r - l <= 1)
    {
        a[l] = l;
        return;
    }
    int m = (r + l) / 2;
    go_to(l, m);
    go_to(m, r);
    int i = l;
    int j = m;
    int k = l;
    while(i < m && j < r)
    {
        if(it == sz(s))
        {
            fl = 0;
            return;
        }
        if(s[it] == '0')
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        it++;
        k++;
    }
    while(i < m)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while(j < r)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    for(int p = l; p < r; p++)
    {
        a[p]=  b[p];
    }
}
signed main()
{
   // ifstream cin("rt.txt.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    int l = 0, r = 1e5 + 1;
    while(r - l > 1)
    {
        int midd = (r + l) / 2;
        it = 0;
        fl = 1;
        go_to(0, midd);
        if(fl)
        {
            l = midd;
        }
        else
        {
            r = midd;
        }
    }
    int n = l;
        it = 0;
        fl = 1;
        go_to(0, n);
        if(fl && it == sz(s))
        {
            vector <int> ans(n);
            for(int i = 0; i < n; i++)
            {
                ans[a[i]] = i + 1;
            }
            cout << n << "\n";
            for(int i = 0; i < n; i++)
                cout << ans[i] << " ";
            return 0;
        }
    return 0;
}