#include <cstdio>
#include <iostream>
using namespace std;
const int N = 100005;
int n, primes[N], tot;
bool st[N];
int main() {
    scanf("%d", &n);
    if(n <= 2) {
        puts("1");
        for (int i = 1; i <= n; i++) printf("1 ");
    } else {
        ++n;
        for (int i = 2; i <= n; i++) {
            if(!st[i]) primes[tot++] = i;
            for (int j = 0; primes[j] * i <= n; j++) {
                st[i * primes[j]] = true;
                if(i % primes[j] == 0) break;
            }
        }
        puts("2");
        for (int i = 2; i <= n; i++) printf("%d ", st[i] + 1);
    }
    return 0;
}