#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int X2;
int cnt[N];
bool notPrime[N];
int divi[N];

int check(int X1) {
    int ret = X1;
    int w = X1;
    while (w > 1) {
        int i = divi[w];
        if (X1 % i == 0 && !notPrime[i]) {
            int from = max(i, i * (X1 / i - 1)) + 1;
            if (from <= X1) {
                ret = min(ret, from);
            }
        }
        w /= i;
    }
    return ret;
}

int main() {

    scanf("%d", &X2);
    
    for (int i = 2; i <= 1000000; i++) {
        if (notPrime[i]) continue;
        divi[i] = i;
        for (int j = 2 * i; j <= 1000000; j += i) {
            notPrime[j] = true;
            divi[j] = i;
        }
    }
    
    vector<int> divisors;
    int w = X2;
    while (w > 1) {
        int i = divi[w];
        if (X2 % i == 0 && !notPrime[i]) {
            divisors.push_back(i);
        }
        w /= i;
    }
    
    for (auto divisor : divisors) {
        int to = X2;
        int from = max(divisor, divisor * (X2 / divisor - 1)) + 1;
        if (from <= to) {
            cnt[from]++;
            cnt[to + 1]--;
        }
    }
    
    int best = X2;
    int sum = 0;
    for (int i = 1; i <= X2; i++) {
        sum += cnt[i];
        if (sum > 0) {
            best = min(best, check(i));
        }
    }
    
    printf("%d\n", best);
    
    return 0;
}