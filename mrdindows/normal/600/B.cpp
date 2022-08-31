#pragma GCC optimize("Os")
#pragma GCC target("avx2,fma")
#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
int a[202201], b[202201], res[202201], n, m;
const int asize = 16;
const int bsize = 256;
#pragma GCC optimize("Ofast")
void count(const int* __restrict a, const int* __restrict b, int* __restrict res) {
    for (int i = 0; i < bsize; i++) {
        for (int j = 0; j < asize; ++j) {
            res[i] += a[j] < b[i];
        }
    }
}
#pragma GCC optimize("Os")
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) std::cin >> a[i];
    for (int i = n; i < n + asize; ++i) a[i] = 1e9 + 7;
    for (int i = 0; i < m; i++) std::cin >> b[i];
    for (int i = 0; i < m; i++) b[i]++;
    const int N = (n + asize - 1) / asize;
    const int M = (m + bsize - 1) / bsize;
    for (int ga = 0; ga < N; ga++)
        for (int gb = 0; gb < M; gb++) 
            count(a + ga * asize, b + gb * bsize, res + gb * bsize);
    for (int i = 0; i < m; i++) std::cout << res[i] << ' ';
    std::cout << std::endl;
    return 0;
}