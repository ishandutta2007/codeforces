#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> data;
vector<long long> vert;
vector<pair<int, int>> gor;

long long a, b, k, n, m, tmp, ans = 1e9;


class Fenwick
    {
    int *m, *mt, N;

    public:
        Fenwick(int n);
        void add_range(int r, int d);
        void add_range(int l, int r, int d);
        int sum(int r);
        int sum(int l, int r);
    };



Fenwick::Fenwick(int n)
    {
    N = n;
    m = new int[N];
    mt = new int[N];
    memset(m, 0, sizeof(int)*N);
    memset(mt, 0, sizeof(int)*N);

    for (int i = 0; i < N; ++i)
        {
        m[i]+= data[i];
        if((i|(i+1)) < N) m[i|(i+1)]+= m[i];
        }
    }

void Fenwick::add_range(int r, int d)
    {
    if (r < 0) return;
    for (int i = r; i >= 0; i = (i&(i+1))-1) mt[i]+= d;
    for (int i = r|(r+1); i < N; i|= i+1) m[i]+= d*(r-(i&(i+1))+1);
    }

void Fenwick::add_range(int l, int r, int d)
    {
    add_range(r, d);
    add_range(l-1, -d);
    }

int Fenwick::sum(int r)
    {
    if(r<0) return 0;
    int res = 0;
    for(int i = r; i >= 0; i = (i&(i+1))-1) res+= m[i] + mt[i]*(i-(i&(i+1))+1);
    for(int i = r|(r+1); i < N; i|= i+1) res+= mt[i]*(r-(i&(i+1))+1);
    return res;
    }

int Fenwick::sum(int l, int r)
    {
    return sum(r) - sum(l-1);
    }


int main()
    {
    FAST;


    cin >> n >> m;
    ++n;

    data.resize(n);
    vert.resize(n);
    gor.resize(m);
    vert.push_back(1e9-1);

    for (int i = 0; i < n; i++)
        data[i] = i;

    Fenwick tree(n);

    vert[0] = 0;
    for (int i = 1; i < n; i++)
        {
        cin >> vert[i];
        vert[i]--;
        }
    sort(vert.begin(), vert.end());

    for (int i = 0; i < m; i++)
        {
        cin >> gor[i].first >> gor[i].second >> tmp;
        --(gor[i].first);
        --(gor[i].second);

        long long low = -1;
        long long high = n;
        while (high - low > 1)
            {
            long long middle = (low + high)/2;
            if (gor[i].first <= vert[middle])
                high = middle;
            else
                low = middle;
            }
        gor[i].first = high;

        low = 0;
        high = n+1;
        while (high - low > 1)
            {
            long long middle = (low + high)/2;
            if (gor[i].second >= vert[middle])
                low = middle;
            else
                high = middle;
            }
        gor[i].second = low-1;

        //cout << gor[i].first << " " << gor[i].second << endl;
        if (gor[i].first <= gor[i].second && gor[i].first == 0) tree.add_range(gor[i].first, gor[i].second, 1);
        }

    for (int i = 0; i < n; i++)
        {
        tmp = tree.sum(i, i);
        if (ans > tmp) ans = tmp;
        }

    cout << ans;

    return 0;
    }