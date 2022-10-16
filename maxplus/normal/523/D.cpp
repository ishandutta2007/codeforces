#include <iostream>
#include <queue>

using namespace std;

priority_queue<int64_t, vector<int64_t>, greater<int64_t>> q;

int main()
{
    int64_t n, k, a, b, t;
    cin.tie(0), ios_base::sync_with_stdio(0), cin >> n >> k;
    while (k--)   q.push(0);
    while (n--)
    {
        cin >> a >> b;
        t = max(int64_t(q.top()), a) + b, q.pop(), q.push(t);
        cout << t << '\n';
    }
    return 0;
}