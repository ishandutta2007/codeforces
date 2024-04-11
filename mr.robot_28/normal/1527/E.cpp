#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
using namespace std;
const int N = 5e4 + 1;
const int K = 110;
int Tree[K][N * 4];
int upd[K][N * 4];
void push(int ind, int v)
{
    Tree[ind][v * 2] += upd[ind][v];
    Tree[ind][v * 2 + 1] += upd[ind][v];
    upd[ind][v * 2] += upd[ind][v];
    upd[ind][v * 2 + 1] += upd[ind][v];
    upd[ind][v] = 0;
}
void update(int ind, int v, int l, int r, int al, int ar, int val)
{
    if(l >= al && r <= ar)
    {
        Tree[ind][v] += val;
        upd[ind][v] += val;
    }
    else if(l <= ar && r >= al)
    {
        push(ind, v);
        update(ind, v * 2, l, (r + l) / 2, al, ar, val);
        update(ind, v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
        Tree[ind][v] = min(Tree[ind][v * 2], Tree[ind][v * 2 + 1]);
    }
}
int get(int ind, int v, int l, int r, int al, int ar)
{
    if(l >= al && r <= ar)
    {
        return Tree[ind][v];
    }
    if(l <=ar && r >= al)
    {
        push(ind, v);
        return min(get(ind, v * 2, l, (r + l) / 2, al, ar), get(ind, v * 2 + 1, (r + l) / 2 + 1, r, al, ar));
    }
    return 1e9;
}
signed main()
{
   // ifstream cin("rt.txt.txt");
 //   ios_base::sync_with_stdio(0);
   // cin.tie(0);
   // cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> a(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int j = 0; j <= k; j++)
    {
        update(j, 1, 0, n, 1, n, 1e9);
    }
    vector <int> last(n + 1, -1);
    for(int i = 1; i <= n; i++)
    {
        if(last[a[i]] != -1)
        {
        //    cout << "A ";
          //  cout << i - last[a[i]] << "\n";
            for(int j = 0; j <= k; j++)
            {
                update(j, 1, 0, n, 0, last[a[i]] - 1, i - last[a[i]]);
            }
        }
        last[a[i]] = i;
        //cout << i << "\n";
        for(int j = 1; j <= k; j++)
        {
            update(j, 1, 0, n, i, i, get(j - 1, 1, 0, n, 0, i - 1) - 1e9);
          //  cout <<j << " " << get(j - 1, 1, 0, n, 0, i) << "\n";
        }
    }
    cout << get(k - 1, 1, 0, n, 0, n - 1);
    return 0;
}