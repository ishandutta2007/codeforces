#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
const int N = 2e5 + 100;
int Tree[20][N * 4];
int it_left[20][N * 4];
int it_right[20][N * 4];
int it_start[20];
int sum[20][N];
void update(int ind, int v, int l, int r, int al, int ar)
{
    if(l >= al && r <= ar)
    {
        Tree[ind][v]++;
    }
    else if(l <= ar && r >= al)
    {
        update(ind, v * 2, l, (r + l) / 2, al, ar);
        update(ind, v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
    }
}
int get(int ind, int v, int l, int r, int x)
{
    if(l == r)
    {
        return Tree[ind][v];
    }
    if(x <= (r + l) / 2)
    {
        return Tree[ind][v] + get(ind, v * 2, l, (r + l) / 2, x);
    }
    return Tree[ind][v] + get(ind, v * 2 + 1, (r + l) / 2 + 1, r, x);
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector <int> cnt(m);
    for(int i = 0; i < 20; i++)
    {
        it_start[i] = 0;
        fill(Tree[i], Tree[i] + 4 * N, 0);
        fill(sum[i], sum[i] + N, 0);
    }
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        a--;
        cnt[a]++;
    }
    int q;
    cin >> q;
    vector <vector <pair <int, int> > > queries(m), queries1(m);
    vector <int> ans(q);
    for(int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        queries[r].push_back({l, i});
        if(l != 0)
        {
            queries1[l - 1].push_back({l, i});
        }
    }
    vector <int> pred(20, 0);
    for(int i = 0; i < m; i++)
    {
        if(cnt[i] & 1)
        {
            for(int j = 0; j < 20; j++)
            {
                int t = i - (1 << j);
                if(t < 0)
                {
                    continue;
                }
                int f = t % (1 << (j + 1));
                if(f >= (1 << j) - 1)
                {
                    update(j, 1, 0, N - 1, f - (1 << j) + 1, f);
                }
                else
                {
                    update(j, 1, 0, N - 1, 0,  f);
                    int d = (1 << j) - (f + 1);
                    update(j, 1, 0, N - 1, (1 << (j + 1)) - d, (1 << (j + 1)) - 1);
                }
            }
        }
        for(auto p : queries1[i])
        {
            for(int j = 0; j < 20; j++)
            {
                int t = (i + 1) % (1 << (j + 1));
                sum[j][p.Y] = get(j, 1, 0, N - 1, t);
            }
        }
        for(auto p : queries[i])
        {
            bool fl = 0;
            int l = p.X;
            for(int j = 0; j < 20; j++)
            {
                int t = l % (1 << (j + 1));
                int s = get(j, 1, 0, N - 1, t);
    //            cout << t << ' ';
      //          cout << p.Y << " " << s << " " << sum[j][p.Y] << "\n";
                s -= sum[j][p.Y];
                if(s & 1)
                {
                    fl = 1;
                }
              //  cout << s << " " << p.Y << "\n";
            }
            //cout << "\n";
            ans[p.Y] = fl;
        }
    }
    for(int i = 0; i < q; i++)
    {
        if(ans[i])
        {
            cout << "A";
        }
        else
        {
            cout << "B";
        }
    }
    return 0;
}