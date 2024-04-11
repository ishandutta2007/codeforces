#include <iostream>
#include <queue>

using namespace std;

int64_t n, b, t, d, lt;
queue<int64_t> q;

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> b;
    for (int i = 0; i < n; ++i)
    {
        cin >> t >> d;
        while (q.size() && q.front() <= t)
            q.pop();
        lt = max(lt, t);
        if (q.size() <= b)
            q.push(lt += d), cout << lt << '\n';
        else
            cout << "-1\n";
    }
    return 0;
}