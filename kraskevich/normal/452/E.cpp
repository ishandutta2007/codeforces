#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000 * 1000 * 1000 + 7;

const int N = 2000 * 1000;

typedef long long LL;

LL f[N];
LL dp1[N];
LL dp2[N];
LL dp3[N];

struct Automaton
{
    vector<int> len, suf;
    vector<map<char, int> > go;
    int p, sz;

    void clear()
    {
        go.clear();
        len.clear();
        suf.clear();
    }

    void build(string s)
    {
        int n = s.length() * 2 + 1;
        len.assign(n, 0);
        suf.assign(n, -1);
        go.resize(n);
        for (int i = 0; i < n; i++)
            go[i].clear();
        p = 0;
        sz = 1;
        for (int i = 0; i < s.length(); i++)
            add(s[i]);
    }

    void add(char c)
    {
        int v = sz++;
        len[v] = len[p] + 1;
        for (; p >= 0 && !go[p].count(c); p = suf[p])
            go[p][c] = v;
        if (p < 0)
        {
            suf[v] = 0;
        }
        else
        {
            int to = go[p][c];
            if (len[to] == len[p] + 1)
            {
                suf[v] = to;
            }
            else
            {
                int cl = sz++;
                go[cl] = go[to];
                len[cl] = len[p] + 1;
                suf[cl] = suf[to];
                for (; p >= 0 && go[p][c] == to; p = suf[p])
                    go[p][c] = cl;
                suf[to] = suf[v] = cl;
            }
        }
        p = v;
    }
};

Automaton a;
bool u[N];

void dfs(int v) {
  if (u[v])
    return;
  u[v] = true;
  if (a.go[v].count('1'))
    dp1[v] = 1;
  if (a.go[v].count('2'))
    dp2[v] = 1;
  if (a.go[v].count('3'))
    dp3[v] = 1;
  for (auto to : a.go[v]) {
    if (to.first < 'a' || to.first > 'z')
      continue;
    dfs(to.second);
    int s = to.second;
    dp1[v] += dp1[s];
    dp1[v] %= MOD;
    dp2[v] += dp2[s];
    dp2[v] %= MOD;
    dp3[v] += dp3[s];
    dp3[v] %= MOD;
  }
}

int main() {
  ios_base::sync_with_stdio(0);

  string s1;
  string s2;
  string s3;
  cin >> s1 >> s2 >> s3;
  string s = s1 + "1" + s2 + "2" + s3 + "3";
  a.build(s);
  dfs(0);
  /*for (int i = 0; i < a.sz; i++) {
    cerr << dp1[i] << " " << dp2[i] << " " << dp3[i] << endl;
  }*/
  for (int i = 0; i < a.sz; i++) {
    if (i == 0)
      continue;
    long long ways = dp1[i] * dp2[i] % MOD * dp3[i] % MOD;
    int r = a.len[i] + 1;
    int l = a.len[a.suf[i]] + 1;
    f[l] += ways;
    f[l] %= MOD;
    f[r] -= ways;
    f[r] += MOD;
    f[r] %= MOD;
  }
  long long cur = 0;
  for (int i = 1; i <= min(s1.length(), min(s2.length(), s3.length())); i++) {
    cur += f[i];
    cur %= MOD;
    cout << cur << " ";
  }
  return 0;
}