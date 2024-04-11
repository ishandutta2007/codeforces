#include <iostream>
using namespace std;

#define ll long long
ll sqr(ll a) {return a * a;}

int main() {
    ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    ll x[n], y[n], t[n];
    double p[n];
    for(int i = 0; i < n; ++i) 
            cin >> x[i] >> y[i] >> t[i] >> p[i];
    for(int i = 0; i < n; ++i)
            for(int j = 0; j < n - 1; ++j)
                    if(t[j] > t[j + 1])
                            swap(x[j], x[j + 1]), swap(t[j + 1], t[j]), swap(p[j + 1], p[j]), swap(y[j + 1], y[j]);
    double f[n];
    for(int i = 0; i < n; ++i) {
            f[i] = p[i];
            for(int j = 0; j < i; ++j)
                    if(sqr(x[i] - x[j]) + sqr(y[i] - y[j]) <= sqr(t[i] - t[j]))
                                f[i] = max(f[i], f[j] + p[i]); 
    }
    double res = 0;
    for(int i = 0; i < n; ++i) 
            res = max(res, f[i]);
    cout.setf(ios::fixed);
    cout.precision(10);
    cout << res;
    cin >> n;                     
    return 0;
}