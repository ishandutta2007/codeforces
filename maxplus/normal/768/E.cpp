#include <iostream>
#include <set>
#include <map>

using namespace std;

int mex[61] = {0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6,
             7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9
            , 10, 10, 10, 10, 10, 10};

int main()
{
    int n = 60, s, ans = 0;
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    while (n--)
        cin >> s,
        ans ^= mex[s];
    cout << "NO\n\0YES\n" + 4 * !ans;
    return 0;
}