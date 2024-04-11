#define push_back pb
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1001;
int a[N];
vector<int> ans;

int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i)
        if (!a[i])
            for (int j = i; j <= n; j += i)
                a[j] = __gcd(a[j], i);
    for (int i = 2; i <= n; ++i)
        if (a[i] != 1)
            ans.pb(i);
    cout << ans.size() << '\n';
    for (auto i: ans)
        cout << i << ' ';
    return 0;
}