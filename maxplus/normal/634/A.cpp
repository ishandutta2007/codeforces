#include <iostream>

using namespace std;

int n, a[200001], b[200001];

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    --n;
    for (int i = 0; i < n; i += !!a[i])
        cin >> a[i];
    for (int i = 0; i < n; i += !!b[i])
        cin >> b[i];
    int s = 0;
    while (b[s] != a[0])
        ++s;
    for (int i = 0; i < n; ++i)
        if (b[(s + i) % n] != a[i])
            return cout << "NO", 0;
    cout << "YES";
    return 0;
}