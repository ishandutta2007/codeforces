#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 10111;

int par[max_n];
int sz[max_n];

int get_set(int a)
{
    if (par[a] == a)
    {
        return a;
    }
    return par[a] = get_set(par[a]);
}

int unite(int a, int b)
{
    int sa = get_set(a);
    int sb = get_set(b);
    if (sz[sa] < sz[sb])
    {
        swap(sa,sb);
    }
    par[sb] = sa;
    sz[sa] += sz[sb];
}

int main()
{
    //ifstream cin("input.txt");
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        par[i] = i;
        sz[i] = 1;
    }
    int a;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        a--;
        unite(i, a);
    }

    set<int> s;
    for (int i = 0; i < n; ++i)
    {
        s.insert(get_set(i));
    }
    cout << s.size();

    return 0;
}