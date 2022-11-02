#include <iostream>
#include <stdlib.h>
using namespace std;

const int maxN = 100 * 1000;
int p[maxN];

int get(int v) {
    return p[v] == v ? v : p[v] = get(p[v]);
}

void unite(int a, int b) {
     a = get(a), b = get(b);
     if(rand() & 1)
               swap(a, b);
     if(a != b)
          p[a] = b;
}

int main() {
    int n;
    cin >> n;
    int num[n];
    for(int i = 0; i < n; ++i)
            num[i] = 0, p[i] = i;
    int m, mod;
    cin >> m >> mod;
    for(int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            unite(--a, --b);
    }
    for(int i = 0; i < n; ++i)
            ++num[get(i)];
    long long res = 1, k = 0;
    for(int i = 0; i < n; ++i) 
            if(num[i])
                      ++k, res = res * num[i] % mod;
    for(int i = 0; i < k - 2; ++i)
            res = res * n % mod;
    if(k == 1)
           res = 1 % mod;
    cout << res;
    cin >> n;
    return 0;
}