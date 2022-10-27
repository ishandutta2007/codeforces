# include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int g = 0,v,cnt = 0,ans = 0;
    while (n --)
    {
        int v;
	    cin >>v;
        g = __gcd(g,v);
        if (v & 1) ++cnt;
        else ans += (cnt / 2) + 2 * (cnt & 1),cnt = 0;
    }
    ans += (cnt / 2) + 2 * (cnt & 1);
    cout << "YES\n";
    if (g == 1)
        cout << ans << '\n';
    else
        cout << "0\n";
    return 0;
}