#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
    long N;
    cin >> N;
    vector<long> primes;
    primes.push_back(2);
    for (long i = 3; i < 1000000; i += 2) {
        bool pr_int = true;
        for (long p: primes) {
            if (i % p == 0) {
                pr_int = false;
                break;
            }
            if (p * p > i) break;
        }
        if (pr_int) primes.push_back(i);
    }
    vector<string> ans;
    for (const long &pr: primes) {
        static string s;
        static string r;
        s = to_string(pr);
        r = "";
        for (char c: s) {
            r = c + r;
        }
        if (s == r) continue;
        long prime = stoi(r);
        bool found = false;

        auto it = lower_bound(primes.begin(), primes.end(), prime);
        if (*it == prime) ans.push_back(s);
    }
    cout << ans[N - 1];
    return 0;
}