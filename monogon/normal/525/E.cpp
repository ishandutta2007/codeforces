
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// all cubes with a[i] >= 19, we cannot put a sticker
// consider putting stickers on the cubes with a[i] <= 18
// all subsets of cubes with a[i] <= 18
// check if sum = s

// in first n / 2 elements, say we choose j <= min(n / 2, k) elements
// in second n / 2 elements, we choose k - j elements
// try each mask and submask in the two halves
// combine answers
// 3^(n / 2) log

const int N = 30;
int n, k;
ll s, a[N], fact[20];
unordered_map<ll, int> ma[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fact[0] = 1;
    rep(i, 1, 20) {
        fact[i] = fact[i - 1] * i;
    }
    cin >> n >> k >> s;
    rep(i, 0, n) {
        cin >> a[i];
    }
    ll cnt = 0, sum = 0;
    rep(mask, 0, 1 << (n / 2)) {
        for(int sub = mask; sub > 0; sub = ((sub - 1) & mask)) {
            sum = 0;
            int bits = __builtin_popcount(sub);
            if(bits > k) continue;
            rep(i, 0, n / 2) {
                if((mask >> i) & 1) {
                    if((sub >> i) & 1) {
                        if(a[i] > 18) goto lab1;
                        sum += fact[a[i]];
                    }else {
                        sum += a[i];
                    }
                }
            }
            ma[bits][sum]++;
            lab1:;
        }
        sum = 0;
        rep(i, 0, n / 2) {
            if((mask >> i) & 1) sum += a[i];
        }
        ma[0][sum]++;
    }
    int m = n - (n / 2);
    rep(mask, 0, 1 << m) {
        for(int sub = mask; sub > 0; sub = ((sub - 1) & mask)) {
            sum = 0;
            int bits = __builtin_popcount(sub);
            if(bits > k) continue;
            rep(i, 0, m) {
                if((mask >> i) & 1) {
                    if((sub >> i) & 1) {
                        if(a[n / 2 + i] > 18) goto lab2;
                        sum += fact[a[n / 2 + i]];
                    }else {
                        sum += a[n / 2 + i];
                    }
                }
            }
            rep(b, 0, k - bits + 1) {
                cnt += ma[b][s - sum];
            }
            lab2:;
        }
        sum = 0;
        rep(i, 0, m) {
            if((mask >> i) & 1) sum += a[n / 2 + i];
        }
        rep(b, 0, k + 1) {
            cnt += ma[b][s - sum];
        }
    }
    cout << cnt << '\n';
}