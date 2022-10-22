#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 2000005;

char tmp[Maxn];
int n, m;
string A, B, S;
string str;
int Z[Maxn];
int vala[Maxn], valb[Maxn];
int BITcnt[Maxn];
ll BITsum[Maxn];
ll res;

void Read(string &s)
{
    scanf("%s", tmp);
    s = tmp;
}

void solveZ()
{
    fill(Z, Z + Maxn, 0);
    int l = -1, r = -1;
    for (int i = 1; i < str.length(); i++) {
        if (i <= r) Z[i] = min(r - i, Z[i - l]);
        while (i + Z[i] < str.length() && str[i + Z[i]] == str[Z[i]])
            Z[i]++;
        if (i + Z[i] - 1 > r) {
            l = i;
            r = i + Z[i] - 1;
        }
    }
}

void solveA()
{
    str = S + "#" + A;
    solveZ();
    for (int i = 0; i < A.length(); i++)
        vala[i] = min(m - 1, Z[S.length() + 1 + i]);
}

void solveB()
{
    str = B + "#" + S;
    reverse(str.begin(), str.end());
    solveZ();
    for (int i = 0; i < B.length(); i++) {
        int rl = int(B.length()) - 1 - i;
        valb[i] = min(m - 1, Z[S.length() + 1 + rl]);
    }
}

void Add(int ind, int cnt, int sum)
{
    for (int i = ind; i > 0; i -= i & -i) {
        BITcnt[i] += cnt;
        BITsum[i] += sum;
    }
}

void Get(int ind, int &cnt, ll &sum)
{
    cnt = 0;
    sum = 0;
    for (int i = ind; i < Maxn; i += i & -i) {
        cnt += BITcnt[i];
        sum += BITsum[i];
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    Read(A);
    Read(B);
    Read(S);
    solveA();
    solveB();
    int l = 0;
    for (int i = 0; i < n; i++) {
        Add(vala[i], 1, vala[i]);
        while (i - l >= m - 1) {
            Add(vala[l], -1, -vala[l]);
            l++;
        }
        int cnt;
        ll sum;
        Get(m - valb[i], cnt, sum);
        res += sum + ll(cnt) * (valb[i] + 1 - m);
    }
    cout << res << endl;
    return 0;
}