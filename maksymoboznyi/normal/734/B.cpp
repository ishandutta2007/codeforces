
 #include <iostream>

using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b>> c>>d;
    long long ans = 0, k = 0;
    k = min(a, min(c, d));
    ans += k*256;
    a -= k;
    ans += min(a, b) * 32;
    cout << ans;
    return 0;
}