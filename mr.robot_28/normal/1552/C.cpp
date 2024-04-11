#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
using namespace std;
const int N =  400;
const int M =  2e5;
int Tree[4 * N];
void upd(int v, int l, int r, int x)
{
    Tree[v]++;
    if(l == r)
    {
        return;
    }
    if(x <= (r + l) / 2)
    {
        upd(v * 2, l, (r + l) / 2, x);
    }
    else
    {
        upd(v * 2 + 1, (r + l) / 2 + 1, r, x);
    }
}
int calc(int v, int l, int r, int al, int ar)
{
    if(al > ar)
    {
        return 0;
    }
    if(l >= al && r <= ar)
    {
        return Tree[v];
    }
    if(l <= ar && r >= al)
    {
        return calc(v * 2, l, (r + l) / 2, al, ar) + calc(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
    }
    return 0;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        fill(Tree, Tree + 4 * N, 0);
        vector <pair <int, int> > x(k + 1);
        vector <int> next(n * 2 + 1, -1);
        vector <bool> open(n * 2 + 2), close(n * 2 + 2);
        for(int i = 0; i < k; i++)
        {
            cin >> x[i].X >> x[i].Y;
            if(x[i].X > x[i].Y)
            {
                swap(x[i].X, x[i].Y);
            }
            open[x[i].X] = 1;
            next[x[i].X] = x[i].Y;
            close[x[i].Y] = 1;
        }
        int cnt = (n - k);
        vector <int> vec;
        for(int i = 1; i <= n * 2; i++)
        {
            if(open[i] || close[i])
            {
                continue;
            }
            vec.push_back(i);
        }
        int s = 0;
        for(int i = 0; i < cnt; i++)
        {
            next[vec[i]] = vec[i + cnt];
        }
        for(int i = 1; i <= n * 2; i++)
        {
            if(next[i] != -1){
                s -= calc(1, 1, n * 2, next[i] + 1, n * 2);
                upd(1, 1, n * 2, next[i]);
            }
            else
            {
                s += calc(1, 1, n * 2, i + 1, n * 2);
            }
        }
        cout << s << "\n";
    }
    return 0;
}