/**
 * @file children.cpp
 * @author Macesuted
 * @date 2021-02-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <bits/stdc++.h>
using namespace std;

template <typename T>
T read(void) {
    char c = getchar();
    T f = 1, num = 0;
    while (c < '0' || c > '9') {
        if (c == '-') f = -f;
        c = getchar();
    }
    while ('0' <= c && c <= '9') {
        num = (num << 3) + (num << 1) + (c ^ 48);
        c = getchar();
    }
    return f * num;
}

#define maxn 1000005

vector<int> prime;
vector<long long> numbers;
bool notPrime[maxn];

void INIT(void) {
    for (register int i = 2; i < maxn; i++) {
        if (!notPrime[i]) prime.push_back(i);
        for (vector<int>::iterator j = prime.begin(); j != prime.end() && 1LL * i * *j < maxn; j++) {
            notPrime[i * *j] = true;
            if (i % *j == 0) break;
        }
    }
    return;
}

int main() {
    // freopen("children.in", "r", stdin), freopen("children.out", "w", stdout);
    INIT();
    long long n = read<long long>(), k = read<long long>();
    k = (k + 1) >> 1;
    while (k-- && n != 1) {
        long long t = n;
        numbers.clear();
        for (vector<int>::iterator i = prime.begin(); i != prime.end() && 1LL * *i * *i <= t; i++)
            if (t % *i == 0) {
                while (t % *i == 0) t /= *i;
                numbers.push_back(*i);
            }
        if (t != 1) numbers.push_back(t);
        int siz = numbers.size(), S = 1 << siz;
        long long ans = n;
        for (register int statu = 1; statu < S; statu++) {
            long long num = 1;
            int cnt = 0;
            for (register int bit = 0; bit < siz; bit++)
                if (statu & (1 << bit)) num *= numbers[bit], cnt++;
            (cnt & 1) ? (ans -= n / num) : (ans += n / num);
        }
        n = ans;
    }
    printf("%lld\n", n % 1000000007);
    return 0;
}