#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int Maxl = 26;

char tmp[Maxn];
int n;
string p[Maxn];
bool ex[Maxn][Maxl];
int res = 1;

void Read(string &s)
{
    scanf("%s", tmp);
    s = tmp;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        Read(p[i]);
        for (int j = 0; j < Maxl; j++)
            ex[i][j] = ex[i - 1][j];
        for (int j = 0; j < p[i].length(); j++)
            ex[i][p[i][j] - 'a'] = true;
    }
    for (int i = 0, j; i < p[n].length(); i = j) {
        j = i;
        while (j < p[n].length() && p[n][i] == p[n][j]) j++;
        res = max(res, j - i);
    }
    int a = 0;
    while (a < p[n].length() && p[n][a] == p[n][0]) a++;
    int b = 0;
    while (b < p[n].length() && p[n][int(p[n].length()) - 1 - b] == p[n][int(p[n].length()) - 1])
        b++;
    if (a < p[n].length())
        if (p[n][0] == p[n][int(p[n].length()) - 1]) {
            if (ex[n - 1][p[n][0] - 'a']) res = max(res, a + 1 + b);
        } else {
            if (ex[n - 1][p[n][0] - 'a']) res = max(res, a + 1);
            if (ex[n - 1][p[n][int(p[n].length()) - 1] - 'a']) res = max(res, b + 1);
        }
    else {
        char let = p[n][0];
        int pw = p[n].length();
        int ind = 0;
        for (int i = n - 1; i > 0; i--) {
            bool sam = true;
            for (int j = 0; j < p[i].length() && sam; j++)
                sam = p[i][j] == let;
            if (sam) pw = pw * (int(p[i].length()) + 1) + int(p[i].length());
            else { ind = i; break; }
        }
        if (ind == 0) res = max(res, pw);
        else {
            int mx = 0;
            for (int i = 0, j; i < p[ind].length(); i = j) {
                j = i;
                while (j < p[ind].length() && p[ind][i] == p[ind][j]) j++;
                if (p[ind][i] == let) mx = max(mx, j - i);
            }
            int a = 0;
            while (a < p[ind].length() && p[ind][a] == let) a++;
            int b = 0;
            while (b < p[ind].length() && p[ind][int(p[ind].length()) - 1 - b] == let) b++;
            if (ex[ind - 1][let - 'a']) mx = max(mx, a + b + 1);
            res = max(res, pw * (mx + 1) + mx);
        }
    }
    printf("%d\n", res);
    return 0;
}