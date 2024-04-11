#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n ; cin >> n ;
    int a[n] ;
    for(auto &x : a) cin >> x ;
    sort(a, a + n, [&](int a, int b){
        if ((a & 1) == (b & 1)) return false;
        if(a & 1) return false ;
        return true ;
    }) ;
    int c = 0 ;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i + 1 ; j < n ; j++)
        {
            if(__gcd(a[i], a[j] << 1) > 1)
            ++c ;
        }
    }
    cout << c << "\n" ;
}
int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ; cout.tie(NULL) ;
    int t = 1 ; cin >> t ;
    while(t--) solve() ;
    return 0 ;
}