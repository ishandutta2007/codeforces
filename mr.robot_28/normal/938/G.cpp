#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
using namespace std;
const int N = 3e5 + 100;
const int mod = 1e9 + 7;
int dsu[N];
int rang[N];
int col[N];
pair <int, int> pred(int a)
{
    if(a == dsu[a])
    {
        return {a, 0};
    }
    else
    {
        pair <int, int> t = pred(dsu[a]);
        return {t.X, t.Y ^ col[a]};
    }
}

vector <vector <int> > otk;
void unite(int a, int b, int d, int v)
{
    pair <int, int> t1 = pred(a);
    pair <int, int> t2 = pred(b);
    if(rang[t1.X] > rang[t2.X])
    {
        swap(t1, t2);
    }
    otk.push_back({t1.X, t1.Y, t2.X, t2.Y, rang[t1.X], rang[t2.X], v});
    rang[t2.X] += rang[t1.X];
    col[t1.X] = d ^ t1.Y ^ t2.Y;
    dsu[t1.X] = t2.X; 
}
int ch[30];
int ans_q[N];
int type[N];
pair <int, int> xy[N];
vector <vector <int> > Tree[4 * N];
vector <vector <int> > vec;
void add(int v, int l, int r, int al, int ar, vector <int> v1){
    if(l >= al && r <= ar)
    {
        Tree[v].push_back(v1);
    }
    else if(l <= ar && r >= al)
    {
        add(v * 2, l, (r + l) / 2, al, ar, v1);
        add(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, v1);
    }
}
int funct(int a)
{
    int c = 0;
    while(a)
    {
        c++;
        a /= 2;
    }
    return c - 1;
}
void go_to(int v, int l, int r)
{
    vector <int> vec1;
    for(int i = 0; i< 30; i++)
    {
        vec1.push_back(ch[i]);
    }
    for(auto p : Tree[v])
    {
        if(pred(p[0]).X != pred(p[1]).X)
        {
            unite(p[0], p[1], p[2], v);
        }
        else
        {
            int tp = pred(p[0]).Y ^ pred(p[1]).Y ^ p[2];
            while(tp)
            {
                int k = funct(tp);
                if(ch[k] == -1)
                {
                    ch[k] = tp;
                }
                tp ^= ch[k];
            }
        }
    }
    if(l == r)
    {
        if(type[l] == 3)
        {
            int d1 = pred(xy[l].X).Y ^ pred(xy[l].Y).Y;
            //cout << d1 << "\n";
            for(int i = 29; i >= 0; i--)
            {
                if(((1 << i) & d1) && ch[i] != -1)
                {
                    d1 ^= ch[i];
                }
            }
            ans_q[l] = d1;
        }
    }
    else
    {
        go_to(v * 2, l, (r + l) / 2);
        go_to(v * 2 + 1, (r + l) / 2 + 1, r);
    }
    while(sz(otk) && otk.back()[6] == v)
    {
        dsu[otk.back()[0]] = otk.back()[0];
        dsu[otk.back()[2]] = otk.back()[2];
        rang[otk.back()[0]] = otk.back()[4];
        rang[otk.back()[2]] = otk.back()[5];
        col[otk.back()[0]] = col[otk.back()[2]] = 0;
        otk.pop_back();
    }
    for(int i =0; i < 30; i++)
    {
        ch[i] = vec1[i];
    }
}
signed main() {
 //   ios_base::sync_with_stdio(0);
   // cin.tie(0);
   // cout.tie(0);
    int n, m;
    cin >> n >> m;
    fill(ch, ch + 30, -1);
    for(int i =0; i < n; i++)
    {
        dsu[i] = i;
        rang[i] = 1;
        col[i] = 0;
    }
    set <pair <pair <int, int>, pair <int, int> > > st;
    for(int i = 0; i < m; i++)
    {
        int x, y, d;
        cin >> x >> y >> d;
        x--;
        y--;
        if(x > y)
        {
            swap(x, y);
        }
        st.insert({{x, y}, {d, 0}});
    }
    int q;
    cin >> q;
    for(int i = 1; i <= q; i++)
    {
        cin >> type[i];
        if(type[i] == 1)
        {
            int x, y, d;
            cin >> x >> y >> d;
            x--;
            y--;
            if(x > y)
            {
                swap(x, y);
            }
            st.insert({{x, y}, {d, i}});
        }
        else if(type[i] == 2)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            if(x > y)
            {
                swap(x, y);
            }
            pair <pair <int, int>, pair <int, int> > stp = *st.lower_bound({{x, y}, {0, 0}});
            st.erase(stp);
     //       cout << stp.X.X << " " << stp.X.Y << " " << stp.Y.X << " " << stp.Y.Y << " " <<i <<  "\n";
            add(1, 0, q, stp.Y.Y, i, {stp.X.X, stp.X.Y, stp.Y.X});
        }
        else
        {
            cin >> xy[i].X >> xy[i].Y;
            xy[i].X--;
            xy[i].Y--;
        }
    }
    while(sz(st))
    {
        pair <pair <int, int>, pair <int, int> > stp = *st.begin();
        st.erase(*st.begin());
     //   cout << stp.X.X << " " << stp.X.Y << " " << stp.Y.X << " " << stp.Y.Y << " " << q << "\n";
        add(1, 0, q, stp.Y.Y, q, {stp.X.X, stp.X.Y, stp.Y.X});
    }
    go_to(1, 0, q);
    for(int i = 1; i <= q; i++)
    {
        if(type[i] == 3)
        {
            cout << ans_q[i] << "\n";
        }
    }
    return 0;
}