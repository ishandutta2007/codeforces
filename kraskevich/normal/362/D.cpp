#include <bits/stdc++.h>

using namespace std;

const long long INF = 1000 * 1000 * 1000;
const int N = (int)1e5 + 10;

long long sum[N];
int p[N];
int n, m;
int comps;
int edges;

int get(int v)
{
    return p[v] == v ? v : p[v] = get(p[v]);
}

map<int, int> hp;

void unite(int a, int b, long long cost)
{
    a = get(a);
    b = get(b);
    if (a != b)
    {
        hp[a] = b;
        p[a] = b;
        sum[b] += sum[a];
    }
    sum[b] += cost;
}

set<pair<long long, int> > q;
vector<int> fr, to;

int main()
{
    ios_base::sync_with_stdio(0);


    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> m >> edges >> comps;
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
        sum[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        --a;
        --b;
        unite(a, b, w);
    }
    for (int i = 0; i < n; i++)
        if (get(i) == i)
        {
            //cerr << i + 1 << " ";
            q.insert(pair<long long, int>(sum[i], i));
        }
    //cerr << endl;

    while (edges > 0 && q.size() > comps)
    {
        pair<long long, int> a, b;
        a = *q.begin();
        q.erase(q.begin());
        b = *q.begin();
        q.erase(q.begin());
        fr.push_back(a.second);
        to.push_back(b.second);
        long long cost = min(a.first + b.first + 1, INF);
        unite(a.second, b.second, cost);
        q.insert(pair<long long, int>(sum[b.second], b.second));
        edges--;
    }
    if (q.size() != comps)
    {
        cout << "NO";
        return 0;
    }
    while (edges > 0)
    {
        if (hp.size() == 0)
        {
            cout << "NO";
            return 0;
        }
        auto f = hp.begin();
        fr.push_back(f->first);
        to.push_back(f->second);
        edges--;
    }

    cout << "YES\n";
    //assert(edges == 0);
    for (int i = 0; i < fr.size(); i++)
        cout << fr[i] + 1 << " " << to[i] + 1 << "\n";

    return 0;
}