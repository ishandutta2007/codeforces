#include <bits/stdc++.h>

using namespace std;

map<long long, int> mem;
vector<long long> R;
vector<long long> len;
vector<int> val;

int get(long long v)
{
    if (mem.count(v))
        return mem[v];
    int pos = lower_bound(R.begin(), R.end(), v) - R.begin();
    long long start = R[pos - 1] + 1;
    if (val[pos] > 0)
        return mem[v] = val[pos];
    return mem[v] = get((v - start) % len[pos]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int m;
    cin >> m;
    R.push_back(-1);
    len.push_back(-1);
    val.push_back(0);
    for (int i = 0; i < m; i++) {
            int t;
            cin >> t;
            if (t == 1) {
                int x;
                cin >> x;
                val.push_back(x);
                len.push_back(1);
                R.push_back(R.back() + 1);
            } else {
                long long l, c;
                cin >> l >> c;
                len.push_back(l);
                val.push_back(0);
                R.push_back(R.back() + l * c);
            }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        --x;
        cout << get(x) << " ";
    }

    return 0;
}