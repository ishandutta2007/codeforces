#include <algorithm>
#include <iostream>
#include <queue>
#define all(a) a.begin(), a.end()

using namespace std;

constexpr int N = 3e5;

bool r[N];
queue<int> a[N];
queue<int> Q;

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    int n, q, mt = 0, am = 0;
    cin >> n >> q;
    while (q--) {
        int t, x;
        cin >> t >> x, --x;
        if (t == 1)
            Q.push(q), a[x].push(q), ++am;
        if (t == 2)
            while (!a[x].empty())
                am -= !r[a[x].front()],
                r[a[x].front()] = 1,
                a[x].pop();
        if (t == 3)
            for (int i = mt; i <= x; ++i, mt = x + 1)
                am -= !r[Q.front()],
                r[Q.front()] = 1,
                Q.pop();
        cout << am << '\n';
    }
    return 0;
}