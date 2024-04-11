#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

long long b, m, bb;
long long ans  = 0, a;
int main()
{
    cin >> m >> bb;
    for (long long a = 0; a <= bb; a++)
    {
        b = (bb-a)*m;
        ans = max(ans, a*(a+1)*(b+1)/2 + b*(b+1)*(a+1)/2);
    }
    cout << ans << endl;
    return 0;
}