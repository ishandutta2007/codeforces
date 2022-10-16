#include <iostream>

using namespace std;

constexpr int N = 1000;

int p[N], s[N], ls[N], n;

int main()
{
    cin >> n;
    for (int i = 1; i < n; ++i)
        cin >> p[i], ++s[--p[i]];
    for (int i = 1; i < n; ++i)
        ls[p[i]] += !s[i];
    for (int i = 0; i < n; ++i)
        if (s[i] && ls[i] < 3)
            return cout << "No", 0;
    cout << "Yes";
    return 0;
}