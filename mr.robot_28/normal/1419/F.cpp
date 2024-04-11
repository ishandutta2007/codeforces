#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <int> dsu, rang;
int pred(int a)
{
    if(a == dsu[a]) return a;
    return dsu[a] = pred(dsu[a]);
}
void unite(int a, int b)
{
    a = pred(a);
    b = pred(b);
    if(a != b)
    {
        if(rang[a]<  rang[b])
        {
            swap(a, b);
        }
        dsu[b] = a;
        rang[a] += rang[b];
    }
}
signed main()
{
//  ios_base::sync_with_stdio(false);
//  cin.tie(NULL);
//  cout.tie(NULL);
    int n;
    cin >> n;
    dsu.resize(n);
    rang.resize(n, 1);
    vector <pair <int, int> > x(n);
    for(int i = 0; i < n; i++)
    {
        cin >> x[i].first >> x[i].second;
    }
    sort(x.begin(), x.end());
    vector <pair <pair <int, int>, int> > y;
    for(int i = 0; i < n; i++)
    {
        y.push_back({{x[i].second, x[i].first}, i});
    }
    sort(y.begin(), y.end());
    int l = -1, r = 2e9 + 2;
    while(r - l > 1)
    {
        int midd = (r + l) / 2;
        for(int i = 0; i< n; i++)
        {
            dsu[i] = i;
            rang[i] = 1;
        }
        for(int i = 0; i < n - 1; i++)
        {
            if(x[i].first == x[i + 1].first && x[i + 1].second - x[i].second <= midd)
            {
                unite(i, i + 1);
            }
        }
        for(int i = 0; i < n - 1; i++)
        {
            if(y[i].first.first == y[i + 1].first.first && y[i + 1].first.second - y[i].first.second <= midd)
            {
                unite(y[i].second, y[i + 1].second);
            }
        }
        set <int> st;
        for(int i = 0; i < n; i++)
        {
            st.insert(pred(i));
        }
        bool fl = 0;
        if(st.size() == 1)
        {
            fl = 1;
        }
        else if(st.size() == 2)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = i + 1; j < n; j++)
                {
                    if(pred(i) != pred(j))
                    {
                        if(x[i].first == x[j].first && abs(x[i].second - x[j].second) <= 2 * midd)
                        {
                            fl = 1;
                        }
                        if(x[i].second == x[j].second && abs(x[i].first - x[j].first) <= 2 * midd)
                        {
                            fl = 1;
                        }
                        if(abs(x[i].second - x[j].second) <= midd && abs(x[i].first - x[j].first) <= midd)
                        {
                            fl = 1;
                        }
                    }
                }
            }
        }
        else if(st.size() == 3)
        {
            for(int i = 0; i < n - 1; i++)
            {
                if(x[i].first == x[i + 1].first && pred(i) != pred(i + 1))
                {
                    for(int j = 0; j < n; j++)
                    {
                        if(pred(j) == pred(i) || pred(j) == pred(i + 1))
                        {
                            continue;
                        }
                        if(abs(x[i].first - x[j].first) <= midd && abs(x[i].second - x[j].second) <= midd && abs(x[i + 1].second - x[j].second) <= midd)
                        {
                            fl = 1;
                        }
                    }
                }
                if(y[i].first.first == y[i + 1].first.first && pred(y[i].second) != pred(y[i + 1].second))
                {
                    for(int j = 0; j < n; j++)
                    {
                        if(pred(y[j].second) == pred(y[i].second) || pred(y[j].second) == pred(y[i + 1].second))
                        {
                            continue;
                        }
                        if(abs(y[i].first.first - y[j].first.first) <= midd && abs(y[i + 1].first.second - y[j].first.second) <= midd && abs(y[i].first.second - y[j].first.second) <= midd)
                        {
                            fl = 1;
                        }
                    }
                }
            }
        }
        else if(st.size() == 4)
        {
            for(int i = 0; i < n - 1; i++)
            {
                if(pred(i) == pred(i + 1) || x[i].first != x[i + 1].first)
                {
                    continue;
                }
                for(int j = 0; j < n - 1; j++)
                {
                    if(y[j].first.first != y[j + 1].first.first)
                    {
                        continue;
                    }
                    if(pred(y[j].second) == pred(y[j + 1].second) || pred(y[j].second) == pred(i) || pred(y[j + 1].second) == pred(i) || pred(y[j].second) == pred(i + 1) || pred(y[j + 1].second) == pred(i + 1))
                    {
                        continue;
                    }
                    int x1 = x[i].first;
                    int y1 = y[j].first.first;
                    if(abs(y1 - x[i].second) <= midd && abs(y1 - x[i + 1].second) <= midd && abs(x1 - y[j].first.second) <= midd && abs(x1 - y[j + 1].first.second) <= midd)
                    {
                        fl = 1;
                    }
                }
            }
        }
        if(fl)
        {
            r = midd;
        }
        else
        {
            l = midd;
        }
    }
    if(r == 2e9 +  2)
    {
        cout << -1;
        return 0;
    }
    cout << r;
    return 0;
}