
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// ABAB: 2

// BAABABAAB
// find the number of good suffixes for each prefix of length i.
// sum of dp[i] is the answer
// for each letter, store last occurrence c[i] of that letter
// dp[i] = dp[c[i] - 1] + 1

// AABBB
// 01023

// substring works if A and B have at least 2 occurrences, or the endpoints are the same character
// #AA + #BB + #AAA + #BBB + ... + #ABA + #BAB + the rest
// use two pointers to find #substrings of "the rest" which start at index i.

const int N = 3e5 + 5;
int n;
string s;
int c[2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    ll sum = 0;
    int cnt = 1;
    vector<ll> v;
    for(int i = 1; i < n; i++) {
        if(s[i] == s[i - 1]) {
            cnt++;
        }else {
            v.push_back(cnt);
            cnt = 1;
        }
    }
    v.push_back(cnt);
    for(unsigned int i = 0; i < v.size(); i++) {
        sum += v[i] * (v[i] - 1) / 2;
        if(i > 1 && v[i - 1] == 1) {
            sum += v[i - 2] * v[i];
        }
    }
    int j = 0;
    c[0] = c[1] = 0;
    for(int i = 0; i < n; i++) {
        while(j < n && (c[0] < 2 || c[1] < 2)) {
            c[s[j] - 'A']++;
            j++;
        }
        if(c[0] >= 2 && c[1] >= 2) {
            sum += n - j + 1;
        }
        c[s[i] - 'A']--;
    }
    cout << sum << endl;
}