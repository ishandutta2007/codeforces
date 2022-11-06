#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

int n, k;
int tab[N];

unordered_set<int> vis;
int ans[N];

bool isPrime[10005];
vector<int> allPrimes;

int main() {

    scanf("%d", &n);
    
    for (int i = 2; i <= 10000; i++) {
        if (!isPrime[i]) {
            isPrime[i] = true;
            allPrimes.push_back(i);
            for (int j = 2 * i; j <= 10000; j += i) {
                isPrime[j] = true;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (x == 0) {
            tab[i] = 0;
            continue;
        }
        int prev = x;
        x = abs(x);
        
        vector<int> primes;
        for (int j : allPrimes) {
            if (j > x) {
                break;
            }
            while (x % j == 0) {
                primes.push_back(j);
                x /= j;
            }
        }
        
        if (x > 0) {
            primes.push_back(x);
        }
        
        int newVal = 1;
        int cnt = 0;
        for (int j = 0; j < primes.size(); j++) {
            if (j == 0 || primes[j] != primes[j - 1]) {
                if (j > 0 && cnt % 2 == 1) {
                    newVal *= primes[j - 1];
                }
                cnt = 0;
            }
            cnt++;
        }
        
        if (cnt % 2 == 1) {
            newVal *= primes.back();
        }
        
        if (prev < 0) newVal *= -1;
        tab[i] = newVal;
    }
    
    for (int i = 1; i <= n; i++) {
        vis.clear();
        for (int j = i; j <= n; j++) {
            if (tab[j] != 0) {
                vis.insert(tab[j]);
            }
            ans[max(1, (int)vis.size())]++;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    
    return 0;
}