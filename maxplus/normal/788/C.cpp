#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

constexpr int N = 1000;
char A[2 * N + 1], *a = A + N + 1, B[2 * N + 1], *b = B + N + 1;
vector<int> pos, pos2;

int main()
{
    int n, k, t, am = 0, l = 0, g = 0;
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> k;
    while (k--)
        cin >> t, a[t - n] = 1, l |= t <= n, g |= t >= n;
    for (int i = -N; i <= N; ++i) if (a[i])
        b[i] = 1, pos.push_back(i);
/// }:-[    if (t && g)
        for (int i = 0; pos.size(); ++i, swap(pos, pos2), pos2.clear())
            if (b[0])
                return cout << i + 1, 0;
            else
                for (int i = 0; i < pos.size(); ++i)
                    for (int j = -N; j <= N; ++j) if (a[j] && j + pos[i] >= -N && j + pos[i] <= N && !b[j + pos[i]])
                        b[j + pos[i]] = 1, pos2.push_back(j + pos[i]);
    cout << -1;
    return 0;
}