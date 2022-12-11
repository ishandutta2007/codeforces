#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int a,b;
        cin >> a >> b;
        int x=__gcd(a,b);
        if(x==1)
            db("Finite")
        else
            db("Infinite")
    }

    return 0;
}