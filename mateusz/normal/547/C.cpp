#include <bits/stdc++.h>

using namespace std;
const int N = 500000;
int isPrime[N + 5];
int primes[N + 5], pSize;
int value[N + 5];
bool added[N + 5];
int n, m, tab[N + 5];
int cnt[N + 5];
int main() {
    for(int i = 2; i <= N; i++) {
        if(isPrime[i] == 0) {
            primes[++pSize] = i;
            for(int j = i; j <= N; j += i) {
                isPrime[j] = i;
            }
        }
    }
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
    }
    int wZbiorze = 0;
    int ans = 0;
    while(m--) {
        int w;
        scanf("%d", &w);
        int x = tab[w];
        vector <int> rozklad;
        while(x > 1) {
            if(find(rozklad.begin(), rozklad.end(), isPrime[x]) == rozklad.end()) {
                rozklad.push_back(isPrime[x]);
            }
            x /= isPrime[x];
        }
        for(int i = 0; i < rozklad.size(); i++) {
            value[(1 << i)] = rozklad[i];
        }
        int size = rozklad.size();
        value[0] = 1;
        if(added[w] == false) {
            wZbiorze++;
            added[w] = true;
            for(int i = 1; i < (1 << size); i++) {
                int lastBit = (i & (-i));
                if((i & lastBit) != i)
                    value[i] = value[i - lastBit] * value[lastBit];
                if(__builtin_popcount(i) % 2) {
                    ans += cnt[value[i]];
                } else {
                    ans -= cnt[value[i]];
                }
                cnt[value[i]]++;
            }
        } else {
            wZbiorze--;
            added[w] = false;
            for(int i = 1; i < (1 << size); i++) { 
                int lastBit = (i & (-i));
                if((i & lastBit) != i)
                    value[i] = value[i - lastBit] * value[lastBit];
                cnt[value[i]]--;
                if(__builtin_popcount(i) % 2) {
                    ans -= cnt[value[i]];
                } else {
                    ans += cnt[value[i]];
                }
            }            
        }
        printf("%I64d\n", (long long)wZbiorze * (wZbiorze - 1) / 2 - ans);
    }
    
    return 0;
}