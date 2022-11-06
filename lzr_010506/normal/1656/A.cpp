#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rep0(i, x) for(int i = 0; i < x; i ++)
#define ll long long
using namespace std;
int T , n , a[2000100] ;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T --)
    {
        cin >> n;
        rep0(i, n) cin >> a[i];

        int mx = a[0] , mn = a[0] , p = 0 , q = 0 ;
        rep0(i, n)
        {
            if (mx < a[i]) mx = a[i] , p = i ;
            if (mn > a[i]) mn = a[i] , q = i ;
        }
        cout << p + 1 << " " << q + 1 << "\n";
    }

    return 0 ;
}