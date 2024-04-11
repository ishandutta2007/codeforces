#include <iostream>
using namespace std;
#define ll long long
int main() {
    ll n;
    cin >> n;
    ll a[100001];
    a[0] = 0;
    for (ll i =1; i<=n;i++){
        ll tmp;
        cin >> tmp;
        a[i] = a[i-1] + tmp;
    }
    ll m;
    cin >> m;

    for (ll i =0;i<m;i++){
        ll tmp;
        cin >> tmp;
        ll l=1, r=n+1;
        ll m;

        // ll debug;
        while (1){
            m = (l+r)/2;
            // cout<< "M " << m <<"L "<< l << "R "<< r<< endl;
            // cout<< tmp << " "<<a[m-1] <<" "<< a[m]<<endl;
            if (tmp > a[m-1] && a[m] >= tmp){
                cout << m << endl;
                break;
            } else if (a[m-1] >= tmp) {
                r = m;
            } else {
                l = m;
            }
        // if (debug++>10) return 1;
        }
    }




}