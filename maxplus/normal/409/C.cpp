#include <iostream>

using namespace std;

int main()
{
    int a1, a2, a3, a4, a5, ans;
    cin >> a1 >> a2 >> a3 >> a4 >> a5;
    ans = a1;
    ans = min(ans, a2);
    ans = min(ans, a3 / 2);
    ans = min(ans, a4 / 7);
    ans = min(ans, a5 / 4);
    cout << ans;
    return 0;
}