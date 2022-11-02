#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> p_pow(1000 * 1001);

void init() {
     p_pow[0] = 1;
     for(int i = 1; i <= 1000 * 1000; ++i)
             p_pow[i] = p_pow[i - 1] * 7;
}

int main() {
    init();
    int n;
    cin >> n;
    int m;
    cin >> m;
    long long a[m], b[m];
    long long h1[n], h2[n];
    for(int i = 0; i < n; ++i)
            h1[i] = 0;
    for(int i = 0; i < m; ++i) {
            cin >> a[i] >> b[i];
            --a[i];
            --b[i];
            h1[a[i]] += p_pow[b[i] + 1];
            h1[b[i]] += p_pow[a[i] + 1];
    }        
    for(int i = 0; i < n; ++i)
            h2[i] = h1[i];
    sort(h1, h1 + n);
    long long res = 0, k = 1;
    for(int i = 1; i < n; ++i)
            if(h1[i] == h1[i - 1])
                     ++k;
            else {
                 res += k * (k - 1) / 2;
                 k = 1;
            }
    res += k * (k - 1) / 2;
    for(int i = 0; i < m; ++i)
            if(h2[a[i]] + p_pow[a[i] + 1] == h2[b[i]] + p_pow[b[i] + 1])
                        ++res;
    cout << res;
    cin >> n;
    return 0;
}