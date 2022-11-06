#include <bits/stdc++.h>

using namespace std;

const int N = 100000;

int n;
bool occurred[N + 5];
int sieve[N + 5];
vector<int> numbers[N + 5];
int cnt[N + 5];
int sign[N + 5];
int reduced[N + 5];

vector<int> factor(int w) {
    vector<int> ret;
    while (w > 1) {
        ret.push_back(sieve[w]);
        w /= sieve[w];
    }
    return ret;
}

void backtrack(vector<int>& factors, int pos, int acc, int toAdd) {
    if (pos == factors.size()) {
        if (acc > 1) {
            cnt[acc] += toAdd;
        }
        return;
    }
    
    backtrack(factors, pos + 1, acc, toAdd);
    backtrack(factors, pos + 1, acc * factors[pos], toAdd);
}

void add(int w, int toAdd) {
    w = reduced[w];
    vector<int> factors = factor(w);
    backtrack(factors, 0, 1, toAdd);
}

int backtrack2(vector<int>& factors, int pos, int acc) {
    if (pos == factors.size()) {
        if (acc > 1) {
            return cnt[acc] * sign[acc];
        }
        return 0;
    }
    
    return backtrack2(factors, pos + 1, acc) + backtrack2(factors, pos + 1, acc * factors[pos]);
}

int comp(int w) {
    w = reduced[w];
    vector<int> factors = factor(w);
    return backtrack2(factors, 0, 1);
}



long long ans = 0;

void check(int gcd) {
//     int low = (int)numbers[gcd].size() - 1;
//     bool good = false;
    vector<int> s;
    for (int i = numbers[gcd].size() - 1; i >= 0; i--) {
        int val = numbers[gcd][i];
        while (!s.empty() && comp(val) < s.size()) {
            ans = max(ans, (long long)gcd * (long long)val * s.back() / __gcd(val, s.back()));
            add(s.back(), -1);
            s.pop_back();
        }
        s.push_back(val);
        add(val, 1);
    }
    while (!s.empty()) {
        add(s.back(), -1);
        s.pop_back();
    }
}

vector<int> per;
// bool good(long long w) {
//     for (int i = 0; i < per.size(); i++) {
//         if (check(per[i], w)) {
//             return true;
//         }
//     }
//     return false;
// }



void solve(int i) {
    check(i);
//     long long low = ans + 1;
//     long long high = 10000000000LL;
//     long long res = ans;
//     while (low <= high) {
//         long long mid = (low + high) / 2;
//         if (check(i, mid)) {
//             res = mid;
//             low = mid + 1;
//         } else {
//             high = mid - 1;
//         }
//     }
//         
//     ans = res;
}

int main() {
    
    auto now = clock();
    srand(time(NULL));
    scanf("%d", &n);
    
    for (int i = 2; i <= N; i++) {
        if (sieve[i] != 0) continue;
        for (int j = i; j <= N; j += i) {
            sieve[j] = i;
        }
    }
 
    for (int i = 2; i <= N; i++) {
        int w = i;
        vector<int> primes;
        while (w > 1) {
            primes.push_back(sieve[w]);
            w /= sieve[w];
        }
        if (primes.size() % 2 == 0) sign[i] = -1;
        else sign[i] = 1;
        primes.resize(unique(primes.begin(), primes.end()) - primes.begin());
        int v = 1;
        for (int p : primes) {
            v *= p;
        }
        reduced[i] = v;
    }
    
    vector<int>a(n + 1);
//     int gcd = -1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        
//         if (gcd == -1) gcd = a[i];
//         else gcd = __gcd(gcd, a[i]);
    }
    
    for (int i = 1; i <= n; i++) {
//         a[i] /= gcd;
        if (occurred[a[i]]) ans = max(ans, (long long)a[i]);
        occurred[a[i]] = true;
    }
    
// //     sort(a.begin(), a.end());
//     a.resize(unique(a.begin(), a.end()) - a.begin());
    
//     ans = 1;
//     for (int i = (int)a.size() - 1; i >= max(1, (int)a.size() - 100); i--) {
//         for (int j = i; j >= max(1, (int)a.size() - 100); j--) {
//             ans = max(ans, (long long)a[i] * a[j] / __gcd(a[i], a[j]));
//         }
//     }
//     
//     for (int i = 1; i <= 100000; i++) {
//         int x = max(1, rand() % (int)a.size());
//         int y = max(1, rand() % (int)a.size());
//         ans = max(ans, (long long)a[x] * a[y] / __gcd(a[x], a[y]));
//     }
//     
//     
//     if (n >= 50000) {
//         printf("%lld\n", ans * gcd);
//         return 0;
//     }
//     
//     long long high = (long long)a.back() * a[a.size() - 2];
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; i * j <= N; j++) {
            if (occurred[i * j]) {
                numbers[i].push_back(j);
            }
        }
    }
    
    
    for (int i = 1; i <= N; i++) {
        if (!numbers[i].empty()) {
            per.push_back(i);
        }
    }
//     reverse(per.begin(), per.end());
//     random_shuffle(per.begin(), per.end());
    for (auto x : per) solve(x);
//     long long low = ans + 1;
//     long long res = ans;
//     while (low <= high && clock() - now < 0.8 * CLOCKS_PER_SEC) {
//         long long mid = (low + high) / 2;
//         if (good(mid)) {
//             res = mid;
//             low = mid + 1;
//         } else {
//             high = mid - 1;
//         }
//     }
    
//     ans = res;
    printf("%lld\n", ans);
    
}