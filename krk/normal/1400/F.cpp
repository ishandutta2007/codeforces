#include <bits/stdc++.h>
using namespace std;

const int K = 10;

struct Vertex {
    int next[K];
    bool leaf = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - '0';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - '0';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
}

const int Maxn = 1005;
const int Maxm = 5005;
const int Inf = 1000000000;

string s;
int X;
vector <char> S;
int dp[Maxn][Maxm];

void maybeAdd()
{
    for (int i = 0; i < S.size(); i++) {
        int cur = 0;
        for (int j = i; j < S.size(); j++) {
            cur += S[j] - '0';
            if (cur != X && X % cur == 0) return;
        }
    }
    string add(S.size(), '?');
    for (int i = 0; i < S.size(); i++)
        add[i] = S[i];
    add_string(add);
}

void Gen(int lft)
{
    if (lft == 0)
        maybeAdd();
    else {
        S.push_back('0');
        for (int num = 1; num <= 9 && num <= lft; num++) {
            S.back() = num + '0';
            Gen(lft - num);
        }
        S.pop_back();
    }
}

int main()
{
    cin >> s;
    cin >> X;
    Gen(X);
    fill((int*)dp, (int*)dp + Maxn * Maxm, Inf);
    dp[0][0] = 0;
    for (int i = 0; i < s.length(); i++)
        for (int j = 0; j < Maxm; j++) if (dp[i][j] < Inf) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            int pos = go(j, s[i]);
            if (!t[pos].leaf) dp[i + 1][pos] = min(dp[i + 1][pos], dp[i][j]);
        }
    int res = Inf;
    for (int j = 0; j < Maxm; j++)
        res = min(res, dp[s.length()][j]);
    printf("%d\n", res);
    return 0;
}