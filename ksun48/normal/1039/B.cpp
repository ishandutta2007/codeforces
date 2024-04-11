#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    mt19937 mt(2859);
    LL n, k;
    cin >> n >> k;
    LL l = 1;
    LL r = n;
    while(1){
        if(l + 50 < r){
            LL m = (l + r) / 2;
            cout << l << " " << m << endl;
            fflush(stdout);
            string ans;
            cin >> ans;
            if(ans == "Yes"){
                if(l == m) return 0;
                r = m;
            } else {
                l = m;
            }
            l -= 10;
            r += 10;
            l = max(1LL, l);
            r = min(n, r);
        } else {
            LL z = mt();
            z = (z % (r-l+1)) + l;
            cout << z << " " << z << endl;
            fflush(stdout);
            string ans;
            cin >> ans;
            if(ans == "Yes") return 0;
            l -= 10;
            r += 10;
            l = max(1LL, l);
            r = min(n, r);
        }
    }
}