#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 105;
const int Maxl = 26;

int A[Maxn][Maxl], sumA[Maxn][Maxl];
int B[Maxn][Maxl], sumB[Maxn][Maxl];
int C[Maxn][Maxl], sumC[Maxn][Maxl];
int n;
char res[Maxn];

char getOne(int ind)
{
    printf("? %d %d\n", ind, ind); fflush(stdout);
    char ch; scanf(" %c", &ch);
    return ch;
}

void Fix(vector <int> &tmp)
{
    assert(!tmp.empty() && tmp.size() <= 2);
    if (tmp.size() == 1) tmp.push_back(tmp[0]);
    sort(tmp.begin(), tmp.end());
}

vector <ii> getSeq(int len, int A[][Maxl], int sumA[][Maxl])
{
    printf("? %d %d\n", 1, len); fflush(stdout);
    for (int i = 0; i < len * (len + 1) / 2; i++) {
        string s; cin >> s;
        for (int j = 0; j < s.length(); j++) {
            A[s.length()][s[j] - 'a'] = (A[s.length()][s[j] - 'a'] + 1) % int(s.length());
            sumA[s.length()][s[j] - 'a']++;
        }
    }
    vector <ii> res;
    vector <int> tmp;
    for (int i = 0; i < Maxl; i++)
        for (int j = 0; j < 2 * sumA[len][i] - sumA[len - 1][i]; j++)
            tmp.push_back(i);
    Fix(tmp);
    res.push_back(ii(tmp[0], tmp[1]));
    int nxt = 3;
    for (int i = 1; 2 * i < len; i++) {
        for (int j = 0; j < i; j++) {
            A[nxt][res[j].first] = (A[nxt][res[j].first] - (j + 1) + nxt) % nxt;
            A[nxt][res[j].second] = (A[nxt][res[j].second] - (j + 1) + nxt) % nxt;
        }
        tmp.clear();
        for (int j = 0; j < Maxl; j++) if (A[nxt][j])
            tmp.push_back(j);
        Fix(tmp);
        res.push_back(ii(tmp[0], tmp[1]));
        nxt++;
    }
    return res;
}

int Oth(const ii &p, int val)
{
    return p.first == val? p.second: p.first;
}

void solvePrefix(int len)
{
    auto seq1 = getSeq(len, A, sumA);
    auto seq2 = getSeq(len - 1, B, sumB);
    int lst;
    for (int i = 0; i < Maxl; i++)
        if (sumA[1][i] > sumB[1][i]) { lst = i; break; }
    res[0] = Oth(seq1[0], lst) + 'a';
    res[len - 1] = lst + 'a';
    int l = 1, r = len - 2;
    while (l <= r) {
        res[r] = Oth(seq2[l - 1], res[l - 1] - 'a') + 'a';
        if (l < r) res[l] = Oth(seq1[l], res[r] - 'a') + 'a';
        l++; r--;
    }
}

void solveSuffix()
{
    auto seq = getSeq(n, C, sumC);
    for (int i = n - 1; i >= n - 1 - i; i--)
        res[i] = Oth(seq[n - 1 - i], res[n - 1 - i] - 'a') + 'a';
}

int main()
{
    cin >> n;
    if (n <= 3) {
        for (int i = 0; i < n; i++)
            res[i] = getOne(i + 1);
        res[n] = '\0';
        printf("! %s\n", res); fflush(stdout);
        return 0;
    }
    int len = max(3, n / 2);
    solvePrefix(len);
    solveSuffix();
    res[n] = '\0';
    printf("! %s\n", res); fflush(stdout);
    return 0;
}