#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, int> pr;

const int N = (int)2e5;

deque<pr> q;
long long val[N];
long long tval[N];
long long a[N], b[N], t[N];

long long absll(long long a)
{
    return a > 0 ? a : -a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);

    int n, m, d;
    cin >> n >> m >> d;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i] >> t[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++)
        val[i] = b[0] - absll(a[0] - i);
    for (int i = 1; i < m; i++)
    {
        long long dd = d * 1ll * (t[i] - t[i - 1]);
        q.clear();
        dd = min(dd, (long long)n - 1);
        //cerr << dd << endl;
        for (int j = 0; j <= dd; j++)
        {
            while (q.size() && q.back().first <= val[j])
                q.pop_back();
            q.push_back(pr(val[j], j));
        }
        int l = dd + 1;
        for (int j = 0; j < n; j++)
        {
            while (q.front().second + dd < j)
                q.pop_front();
            assert(q.size());
            tval[j] = q.front().first + b[i] - absll(a[i] - j);
            if (l < n)
            {
                while (q.size() && q.back().first <= val[l])
                    q.pop_back();
                q.push_back(pr(val[l], l));
                l++;
            }
        }
        copy(tval, tval + n, val);
    }
    cout << *max_element(val, val + n);

    return 0;
}