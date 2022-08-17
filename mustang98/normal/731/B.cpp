#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
typedef long long ll;

const int max_n = 200008;

int main()
{
    int n;
    int m[max_n];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin>>m[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (m[i] % 2 == 0) continue;
        if (m[i + 1] == 0) {
            cout << "NO";
            return 0;
        }
        m[i + 1]--;
    }
    if (m[n - 1] % 2 == 1) cout << "NO";
    else cout << "YES";
    return 0;
}