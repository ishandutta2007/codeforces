#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 105;
const int Maxd = 24 * 60;
const int Maxm = Maxd * 32;
const int Inf = 1000000000;

int m, n, k;
map <string, int> M;
int T[Maxn];
vector <ii> seq;
int ex[Maxn], tim[Maxn], mon[Maxn];
vector <ii> st;
int dp[Maxn][Maxm];
ii from[Maxn][Maxm];
int sinc[Maxn][Maxm];

int getLst(int tim, int nd)
{
    if (seq.size() == 1 && seq[0].second - seq[0].first + 1 >= Maxd) return Maxm;
    int pnt = 0;
    for (int i = 0; i < seq.size(); i++)
        if (seq[i].first <= tim % Maxd && tim % Maxd <= seq[i].second) {
            tim = tim - tim % Maxd + seq[i].second + 1;
            pnt = (i + 1) % int(seq.size());
            break;
        } else if (tim % Maxd < seq[i].first) { pnt = i; break; }
    if (seq[pnt].first <= tim % Maxd && tim % Maxd <= seq[pnt].second) {
        tim = tim - tim % Maxd + seq[pnt].second + 1;
        pnt = (pnt + 1) % int(seq.size());
    }
    while (nd && tim < Maxm) {
        if (tim % Maxd <= seq[pnt].first) {
            int col = seq[pnt].first - tim % Maxd;
            if (col >= nd) return tim + nd - 1;
            nd -= col;
            tim = tim - tim % Maxd + seq[pnt].second + 1;
        } else {
            int col = seq[pnt].first + Maxd - tim % Maxd;
            if (col >= nd) return tim + nd - 1;
            nd -= col;
            tim = tim - tim % Maxd + seq[pnt].second + 1 + Maxd;
        }
        pnt = (pnt + 1) % int(seq.size());
    }
    return tim;
}

int Count(int i, int j)
{
    if (sinc[i][j] == -1) return 0;
    return 1 + Count(from[i][j].first, from[i][j].second);
}

void printTime(int tim)
{
    printf("%d ", tim / Maxd + 1);
    tim %= Maxd;
    printf("%d%d:", tim / 60 / 10, tim / 60 % 10);
    tim %= 60;
    printf("%d%d", tim / 10, tim % 10);
}

void Print(int i, int j)
{
    if (sinc[i][j] == -1) return;
    Print(from[i][j].first, from[i][j].second);
    printf("%d ", st[from[i][j].first].second + 1);
    printTime(sinc[i][j]); printf(" ");
    printTime(j); printf("\n");
}

int main()
{
    scanf("%d %d %d", &m, &n, &k);
    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        M[s] = i;
    }
    for (int i = 0; i < m; i++)
        scanf("%d", &T[i]);
    for (int i = 0; i < 4; i++) {
        string s; cin >> s;
        for (int j = 0; j < s.length(); j++)
            if (s[j] == ':' || s[j] == '-')
                s[j] = ' ';
        stringstream ss(s);
        int h1, m1, h2, m2; ss >> h1 >> m1 >> h2 >> m2;
        int val1 = h1 * 60 + m1;
        int val2 = h2 * 60 + m2;
        if (val1 > val2) {
            seq.push_back(ii(val1, Maxd - 1));
            seq.push_back(ii(0, val2));
        } else seq.push_back(ii(val1, val2));
    }
    sort(seq.begin(), seq.end());
    vector <ii> tmp;
    for (int i = 0; i < seq.size(); i++)
        if (!tmp.empty() && tmp.back().second + 1 == seq[i].first)
            tmp.back().second = seq[i].second;
        else tmp.push_back(seq[i]);
    seq = tmp;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int d;
        string tmp;
        cin >> d >> tmp >> mon[i];
        map <string, int>::iterator it = M.find(s);
        if (it == M.end()) continue;
        ex[i] = it->second;
        for (int j = 0; j < tmp.size(); j++)
            if (tmp[j] == ':') tmp[j] = ' ';
        stringstream ss(tmp);
        int h, m; ss >> h >> m;
        tim[i] = (d - 1) * Maxd + h * 60 + m;
      /*  int lef = 0, rig = Maxm - 1;
        while (lef <= rig) {
            int m = lef + rig >> 1;
            if (getLst(m, T[ex[i]]) < tim[i]) lef = m + 1;
            else rig = m - 1;
        }*/
        st.push_back(ii(tim[i], i));
    }
    sort(st.begin(), st.end());
    fill((int*)dp, (int*)dp + Maxn * Maxm, -Inf);
    dp[0][0] = 0; sinc[0][0] = -1;
    for (int i = 0; i < st.size(); i++)
        for (int j = 0; j < Maxm; j++) if (dp[i][j] >= 0) {
            if (dp[i][j] > dp[i + 1][j]) {
                dp[i + 1][j] = dp[i][j];
                from[i + 1][j] = from[i][j];
                sinc[i + 1][j] = sinc[i][j];
            }
            int a = i == 0 && j == 0? getLst(j, 1): getLst(j + 1, 1);
            int b = i == 0 && j == 0? getLst(j, T[ex[st[i].second]]): getLst(j + 1, T[ex[st[i].second]]);
            if (b < tim[st[i].second] && dp[i][j] + mon[st[i].second] > dp[i + 1][b]) {
                dp[i + 1][b] = dp[i][j] + mon[st[i].second];
                from[i + 1][b] = ii(i, j);
                sinc[i + 1][b] = a;
            }
        }
    int bestj = 0;
    for (int j = 0; j < Maxm; j++)
        if (dp[st.size()][j] > dp[st.size()][bestj])
            bestj = j;
    printf("%d\n", dp[st.size()][bestj]);
    printf("%d\n", Count(st.size(), bestj));
    Print(st.size(), bestj);
    return 0;
}