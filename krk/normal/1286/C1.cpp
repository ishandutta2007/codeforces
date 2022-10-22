#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 105;
const int Maxl = 26;

int A[Maxn][Maxl];
int n;
char res[Maxn];

char getFirst()
{
    printf("? 1 1\n"); fflush(stdout);
    char ch; scanf(" %c", &ch);
    return ch;
}

void Solve(int fir, int len, vector <ii> &res)
{
    for (int i = 0; i <= len; i++)
        fill(A[i], A[i] + Maxl, 0);
    if (len == 1) { res.push_back(ii(fir, fir)); return; }
    printf("? %d %d\n", 1, len); fflush(stdout);
    for (int i = 0; i < len * (len + 1) / 2; i++) {
        string s; cin >> s;
        for (int j = 0; j < s.length(); j++)
            A[s.length()][s[j] - 'a'] = (A[s.length()][s[j] - 'a'] + 1) % int(s.length());
    }
    A[2][fir] = (A[2][fir] + 1) % 2;
    for (int j = 0; j < Maxl; j++)
        if (A[2][j]) { res.push_back(ii(fir, j)); break; }
    int nxt = 3;
    for (int i = 1; 2 * i < n; i++) {
        for (int j = 0; j < i; j++) {
            A[nxt][res[j].first] = (A[nxt][res[j].first] - (j + 1) + nxt) % nxt;
            A[nxt][res[j].second] = (A[nxt][res[j].second] - (j + 1) + nxt) % nxt;
        }
        vector <int> tmp;
        for (int j = 0; j < Maxl; j++) if (A[nxt][j])
            tmp.push_back(j);
        assert(!tmp.empty() && tmp.size() <= 2);
        if (tmp.size() == 1) tmp.push_back(tmp[0]);
        res.push_back(ii(tmp[0], tmp[1]));
        nxt++;
    }
}

int Oth(const ii &p, int val)
{
    return p.first == val? p.second: p.first;
}

int main()
{
    cin >> n;
    char fir = getFirst();
    if (n == 1) { printf("! %c\n", fir); fflush(stdout); return 0; }
    vector <ii> seq1, seq2;
    Solve(fir - 'a', n, seq1);
    Solve(fir - 'a', n - 1, seq2);
    res[0] = fir;
    res[n - 1] = Oth(seq1[0], fir - 'a') + 'a';
    int l = 1, r = n - 2;
    while (l <= r) {
        res[r] = Oth(seq2[l - 1], res[l - 1] - 'a') + 'a';
        if (l < r) res[l] = Oth(seq1[l], res[r] - 'a') + 'a';
        l++; r--;
    }
    res[n] = '\0';
    printf("! %s\n", res); fflush(stdout);
    return 0;
}