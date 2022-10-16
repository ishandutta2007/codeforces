#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct task {
    int a, t, n;
};

constexpr int N = 200001;

task t[N];
vector<int> b[N];

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    int n, T;
    cin >> n >> T;
    for (int i = 0; i < n; ++i)
        cin >> t[i].a >> t[i].t, t[i].n = i;
    sort(t, t + n, [](task a, task b) { return a.t < b.t; });
    for (int i = 0; i < n; ++i)
        b[t[i].a].push_back(i);
    for (int am = 0, r = 0, ct = 0; ; ) {
        int ram = am++;
        for (auto i: b[am - 1])
            if (i < r)
                --ram, ct -= t[i].t;
        while (ram < am && r < n && ct + t[r].t <= T)
            if (t[r++].a >= am)
                ct += t[r - 1].t, ++ram;
        if (ram < am) {
            cout << --am << '\n';
            cout << am << '\n';
            for (int i = 0, ram = 0; ram < am; ++i)
                if (t[i].a >= am)
                    cout << t[i].n + 1 << ' ', ++ram;
            return 0;
        }
    }
}