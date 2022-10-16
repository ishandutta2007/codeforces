#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 998244353 ;
const int maxn = 2001;

int pw[maxn];
vector<int> acc;

int memo[maxn][maxn];

string s;

int solve(int b, int e) {
    if (memo[b][e] != -1)
        return memo[b][e];

    if (e <= b)
        return 0;

    if (s[b] == ')'){
        return memo[b][e] = solve(b + 1, e);
    }

    if (s[e] == '('){
        return memo[b][e] = solve(b, e - 1);
    }

    int t = pw[acc[e - 1] - acc[b]];
    int64 answer = 0;

    if (s[b] == '(') {
        if (s[e] == ')'){
            answer += t + solve(b + 1, e - 1);
        } else {
            answer += t + solve(b + 1, e - 1);
            answer += solve(b, e - 1);
        }
    } else {
        if (s[e] == ')') {
            answer += t + solve(b + 1, e - 1);
            answer += solve(b + 1, e);
        } else {
            answer += t + solve(b + 1, e - 1);
            answer += solve(b, e - 1);
            answer += solve(b + 1, e);
            answer -= solve(b + 1, e - 1);
        }
    }

    answer %= mod;

    return memo[b][e] = answer;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(memo, -1, sizeof memo);

    cin >> s;

    pw[0] = 1;

    for (int i = 1; i < maxn; ++i){
        pw[i] = pw[i - 1] * 2;
        if (pw[i] >= mod)
            pw[i] -= mod;
    }

    acc = vi(s.length() + 1);

    for (int i = 1; i <= (int)s.length(); ++i){
        if (s[i - 1] == '?')
            acc[i]++;
        acc[i] += acc[i - 1];
    }

    s = "$" + s;
    cout << solve(1, s.length() - 1) << endl;

    return 0;
}