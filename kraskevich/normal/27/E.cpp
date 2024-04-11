#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define ll long long

ll inf = 1e18 + 2;

bool prime(int n) {
     for(int i = 2; i * i <= n; ++i)
             if(n % i == 0)
                  return false;
     return true;
}

ll mult(ll a, ll b) {
           if(inf / b < a || a * b < 0)
                  return inf;
           else
               return min(a * b, inf);
}

int main() {
    int n;
    cin >> n;
    vector<ll> p;
    p.push_back(0);
    for(int i = 2; p.size() < 11; ++i)
            if(prime(i))
                        p.push_back(i);
    ll d[11][1001];
    for(int i = 0; i < 11; ++i)
            for(int j = 0; j <= 1000; ++j)
                    d[i][j] = inf;
    d[0][1] = 1;
    for(int i = 1; i <= 10; ++i) 
            for(ll j = 1; j <= n; ++j) {
                   ll cur = 1; 
                   for(int k = 0; cur < inf; ++k) {
                           if(j % (k + 1) == 0) 
                                d[i][j] = min(d[i][j], mult(d[i - 1][j / (k + 1)], cur));
                           cur = mult(cur, p[i]);
                   }
            }
    cout << d[10][n];
    cin >> n;
    return 0;
}