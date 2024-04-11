#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
using namespace std;
#define ll long long
const int N = 1e5 + 100;

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll sum;
        cout << "? " << 1 << " " << n << endl;
        cin >> sum;
        int l1 = 0, r1 = n;
        while(l1 < r1){
            int midd1 = (l1 + r1 + 1) / 2;
            cout << "? " << 1 << " " << midd1 << endl;
            ll x;
            cin >> x;
            if(x == -1){
                return 0;
            }
            if(x != 0){
                r1 = midd1 - 1;
            }
            else{
                l1 = midd1;
            }
        }
        cout << "? " << l1 + 1 << " " << n << endl;
        ll x;
        cin >> x;
        if(x == -1){
            return 0;
        }
        ll len1 = 1 + sum - x;
    //    cout << len1 << "\n";
        int p1 = 1, p2 = n;
        while(p2 > p1){
            int midd = (p1 + p2 + 1) / 2;
            if(1LL * midd * (midd - 1) / 2 + len1 * (len1 - 1) / 2 <= sum){
                p1 = midd;
            }
            else{
                p2 = midd - 1;
            }
        }
        ll len2 = p1;
        cout << "! " << l1 << " " << l1 + len1 << " " << l1 + len1 + len2 - 1 << endl;
    }
    return 0;
}