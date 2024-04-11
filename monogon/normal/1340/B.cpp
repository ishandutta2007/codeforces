
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// what a retarded problem

const int N = 2005;
int n, k;
bool dp[N][N];
int par[N][N];
string s[N];
string dig[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int digint[10];
int score[N];

int toint(string s) {
    int x = 0;
    for(int i = 0; i < 7; i++) {
        if(s[i] == '1') {
            x += (1 << i);
        }
    }
    return x;
}

// if a subset of b, how many do they differ
inline int dif(int a, int b) {
    if((a & b) != a) return -1;
    return __builtin_popcount(b - a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> s[n - i + 1];
        score[n - i + 1] = toint(s[n - i + 1]);
    }
    for(int i = 0; i < 10; i++) {
        digint[i] = toint(dig[i]);
    }
    dp[0][0] = true;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            for(int d = 0; d < 10; d++) {
                int k = dif(score[i], digint[d]);
                if(k != -1 && k <= j && dp[i - 1][j - k]) {
                    dp[i][j] = true;
                    par[i][j] = d;
                }
            }
        }
    }
    if(!dp[n][k]) {
        cout << "-1\n";
        return 0;
    }
    int j = k;
    for(int i = n; i > 0; i--) {
        cout << par[i][j];
        j -= dif(score[i], digint[par[i][j]]);
    }
    cout << '\n';
}