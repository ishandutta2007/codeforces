#include<cstdio>
#include<cstring>

using ll = long long ;

int n, len;
char s[42];
ll dp[42][42][42][2], ans;
int trans[42][2];


ll rec (int pos, int suf, int state, bool done) {
    ll &res = dp[pos][suf][state][done];
    if (res != -1) return res;
    else if (state == len && !done) {
        return res = rec(pos, suf, state, true);
    } else if (pos == n) {
        return done && state == suf ? 1 : 0;
    } else return res = rec(pos + 1, suf, trans[state][0], done) + rec(pos + 1, suf, trans[state][1], done);
}

int pi[42];

int main () {
    scanf("%d", &n);
    scanf("%s", s);

    std::memset(dp, -1, sizeof(dp));
    len = strlen(s);
    /// compute transition

    trans[0][s[0] - '0'] = 1; /// prefix-function or kmp value change when add letter

    for (int i = 1 ; i <= len ; ++ i) {
        pi[i] = i == 1 ? 0 : trans[pi[i - 1]][s[i - 1] - '0'];

        trans[i][0] = trans[pi[i]][0];
        trans[i][1] = trans[pi[i]][1];

        if (i != len) trans[i][s[i] - '0'] = i + 1;
    }

    for (int i = 0 ; i <= len ; ++ i) {
        ans += rec(0, i, i, 0);
    }

    printf("%lld\n", ans);
}