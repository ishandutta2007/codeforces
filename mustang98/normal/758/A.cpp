#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100005;

int main()
{
    //ifstream cin("input.txt");
    int ans = 0;
    int m[150];
    int n;
    int maxa = -1;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> m[i];
        maxa = max(maxa, m[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        ans += maxa - m[i];
    }
    cout << ans;
    return 0;
}