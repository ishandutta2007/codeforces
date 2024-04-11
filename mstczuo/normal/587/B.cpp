# include <iostream>
# include <cstdio>
# include <cstring>
# include <algorithm>

using namespace std;

const int Mod = 1000000007;

int N, K;
long long L;

int F[2000010];
int a[2000010];
int e[2000010];

void DP() {
    for(int i = 0; i < N; ++i) F[i] = 1;
    for(int k = 1; k < K; ++k) {
        int i, j, sum = 1;
        for(i = 0; i < N; i = j) {
            for(j = i; j < N && a[e[j]] == a[e[i]]; ++j) {
                sum = (sum + F[(k - 1) * N + e[j]]) % Mod;
            }
            for(j = i; j < N && a[e[j]] == a[e[i]]; ++j) {
                F[k * N + e[j]] = sum;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < N * K; ++i)
        if(i < L) ans = (ans + F[i]) % Mod; else break;
    if(L > N * K) {
        L -= N * K;
        for(int i = 0; i < N; ++i) {
            long long t = (L + N - i - 1) / N % Mod;
            ans = (ans + t * F[(K - 1) * N + i]) % Mod;
        }
    }
    cout << ans << endl;
}

bool cmp(int i,int j) { return a[i] < a[j]; }

int main() {
    cin >> N >> L >> K;
    for(int i = 0; i < N; ++i) scanf("%d", &a[i]);
    for(int i = 0; i < N; ++i) e[i] = i;
    sort(e, e + N, cmp); DP();
}