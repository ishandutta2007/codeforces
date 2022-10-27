#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
const int N = 1e5 + 100;
struct query{
    int t, l, r, k, i;
};
const int P = 2000;
vector <int> cnt(N), ord(N);
vector <pair <int, int> > bounds(N, {N, 0});
bool cmp(query a, query b)
{
    if(a.t / P != b.t / P)
    {
        return a.t / P < b.t / P;
    }
    if(a.l / P != b.l / P)
    {
        return a.l / P < b.l / P;
    }
    if((a.l / P) & 1)
    {
        return a.r < b.r;
    }
    return a.r > b.r;
}
int a[N];
void add(int a)
{
    int c = cnt[a];
    ++ord[bounds[c].X];
    bounds[c + 1].Y = bounds[c].X;
    if(bounds[c + 1].X == N)
    {
        bounds[c + 1].X = bounds[c].X;
    }
    if(bounds[c].X == bounds[c].Y)
    {
        bounds[c].X = N - 1;
    }
    bounds[c].X++;
    ++cnt[a];
}
void del(int a)
{
    int c = cnt[a];
    --ord[bounds[c].Y];
    if(bounds[c - 1].X == N)
    {
        bounds[c - 1].Y = bounds[c].Y;
    }
    bounds[c - 1].X = bounds[c].Y;
    if(bounds[c].X == bounds[c].Y)
    {
        bounds[c].X = N;
    }
    bounds[c].Y--;
    --cnt[a];
}
int L = 0, R = -1, T = -1;
void add(vector <int> up)
{
    int p = up[0];
    if(p >= L && p <= R)
    {
        del(up[1]);
        add(up[2]);
    }
    a[p] = up[2];
}
void del(vector <int> up)
{
    int p = up[0];
    if(p >= L && p <= R)
    {
        del(up[2]);
        add(up[1]);
    }
    a[p] = up[1];
}
signed main()
{
//    ios_base::sync_with_stdio(0);
  //  cin.tie(0);
    //cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector <query> q;
    vector <vector <int> > upd;
    for(int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int l, r, k;
            cin >> l >> r >> k;
            l--;
            r--;
            q.push_back({sz(upd), l, r, k, sz(q)});
        }
        else
        {
            int p, x;
            cin >> p >> x;
            p--;
            upd.push_back({p, a[p], x});
            a[p] = x;
        }
    }
    for(int i = sz(upd) - 1; i >= 0; i--)
    {
        a[upd[i][0]] = upd[i][1];
    }
    bounds[0] = {0, N - 1};
    sort(q.begin(), q.end(), cmp);
    vector <int> qans(m);
    for(int i = 0; i < sz(q); i++)
    {
     //   cout << q[i].t << " " << q[i].l << " " << q[i].r << " " << q[i].k << "\n";
        while(T < q[i].t - 1)
        {
            T++;
            add(upd[T]);
        }
        while(T > q[i].t - 1)
        {
            del(upd[T]);
            T--;
        }
        while(L > q[i].l)
        {
            L--;
            add(a[L]);
        }
        while(R < q[i].r)
        {
            R++;
            add(a[R]);
        }
        while(R > q[i].r)
        {
            del(a[R]);
            R--;
        }
        while(L < q[i].l)
        {
            del(a[L]);
            L++;
        }
      //  cout << "B\n";
        int ans = 1e9;
      //  cout << q[i].i << "\n";
        for(int it = 0, it1 = 0, sum = 0; it < N && ord[it] > 0; it = bounds[ord[it]].Y + 1)
        {
        //    cout << ord[it] << " " << bounds[ord[it]].X << " " << bounds[ord[it]].Y << "\n";
            while(it1 < N && ord[it1] > 0 && sum < q[i].k)
            {
                sum += bounds[ord[it1]].Y - bounds[ord[it1]].X + 1;
                it1 = bounds[ord[it1]].Y + 1;
            }
            if(sum >= q[i].k)
            {
                ans = min(ans,ord[it] - ord[it1 - 1]);
            }
            sum -= bounds[ord[it]].Y - bounds[ord[it]].X + 1;
        }
  //      cout << "A\n";
        if(ans == 1e9)
        {
            qans[q[i].i] = -1;
        }
        else
        {
            qans[q[i].i] = ans;
        }
    }
    for(int i = 0; i < sz(q); i++)
    {
        cout << qans[i] << "\n";
    }
    return 0;
}