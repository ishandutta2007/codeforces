#include <bits/stdc++.h>

using namespace std;

const int N = 19;

long long dp[19][4];
long long power[N + 5], fact[N + 5];

long long choose(long long n, long long k) {
    if (k > n) return 0;
    return fact[n] / fact[k] / fact[n - k];
}

long long combi(long long pos, long long zeros) {
    pos++;
//     cerr << pos << " " << zeros << endl;
    return choose(pos, zeros) * power[zeros];
}

long long combi2(long long pos, long long zeros) {
    pos++;
//     int add = 0;
//     if (pos == 1 && zeros == 0) {
//         return 1;
//     }
//     cerr << pos << " " << zeros << endl;
    return choose(pos - 1, zeros - 1) * power[zeros] + 1;
}

long long solve(long long n) {
    if (n == 0) return 1;
    vector<int> digits;
    long long w = n;
    for (int i = 0; i < 19; i++) {
        digits.push_back(w % 10);
        w /= 10;
    }
    dp[0][0] = 1;
    dp[0][1] = digits[0];
    bool wasNoZero[19];
    for (int i = 18; i >= 0; i--) {
        if ((i < 18 && wasNoZero[i + 1]) || digits[i] > 0) {
            wasNoZero[i] = true;
        } else {
            wasNoZero[i] = false;
        }
    }
    for (int i = 1; i < 19; i++) {
        for (int j = 0; j <= 3; j++) {
            if (wasNoZero[i] == false) {
                dp[i][j] = dp[i - 1][j];
                continue;
            }
            dp[i][j] = 0;
            if (j > 0) {
                dp[i][j] = max(0, (digits[i] - 1)) * combi(i - 1, j - 1);
            }
            if (i < 18 && wasNoZero[i + 1]) {
                if (digits[i] == 0) {
                    dp[i][j] += dp[i - 1][j];
                } else {
                    dp[i][j] += combi(i - 1, j);
                }
            }
            if ((i == 18 || (i < 18 && !wasNoZero[i + 1])) && digits[i] > 0) {
                dp[i][j] += combi(i - 1, j);
            } 
            if (digits[i] == 0) {
                continue;
            }
            if (j > 0) {
                dp[i][j] += dp[i - 1][j - 1];
            }
        
        }
    }
/*    
    cerr << "Wypisuje tablice:\n";
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j <= 3; j++) {
            cerr << dp[i][j] << " ";
        }
        cerr << endl;
    }
    */
    
    return dp[18][0] + dp[18][1] + dp[18][2] + dp[18][3];
}

int main() {
    
    power[0] = 1;
    for (int i = 1; i <= 20; i++) {
        power[i] = power[i - 1] * 9;
    }
    fact[0] = 1;
    for (int i = 1; i <= 20; i++) {
        fact[i] = fact[i - 1] * i;
    }
    
    int t;
    scanf("%d", &t);
    while (t--) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
//         cerr << solve(1000) << endl;
//         cerr << solve(a - 1) << " " << solve(b) << endl;
        printf("%lld\n", solve(b) - solve(a - 1));
    }

    return 0;
}