#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)a.size()

using namespace std;
int n;
//#define int long long
int funct(int i)
{
    cout << "? " << i + 1 << endl;
    fflush(stdout);
    int x;
    cin >> x;
    cout <<"? " << n / 2 + i + 1 << endl;
    fflush(stdout);
    int x1;
    cin >> x1;
    return x1 - x;
}
int32_t main() {
 //   ios::sync_with_stdio(0);
   // cin.tie(0);
    cin >> n;
    int t = funct(0);
    if(abs(t) % 2 != 0)
    {
        cout << "! " << -1;
        return 0;
    }
    int t1 = funct(0 + n / 2 - 1);
    int l = 0, r = n / 2 - 1;
    while(r > l)
    {
        int midd = (r + l) / 2;
        int d = funct(midd);
        if(d == 0)
        {
            cout << "! " << midd + 1 << endl;
            fflush(stdout);
            return 0;
        }
        if(d * t > 0)
        {
            l = midd + 1;
        }
        else
        {
            r = midd - 1;
        }
    }
    cout << "! " << l + 1 << endl;
    fflush(stdout);
    return 0;
}