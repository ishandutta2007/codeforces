#include <bits/stdc++.h>
using namespace std;

const int Inf = 100000000;

string s;

int moveZers(const string &s)
{
    if (s[0] != '0') return 0;
    for (int i = 0; i + 2 < s.length(); i++)
        if (s[i] != '0') return i;
    return Inf;
}

int Solve2(string s, int a)
{
    int res = Inf;
    for (int i = 0; i + 1 < s.length(); i++) if (s[i] - '0' == a) {
        string cp = s;
        int cand = 0;
        for (int j = i; j + 2 < s.length(); j++) { swap(cp[j], cp[j + 1]); cand++; }
        cand += moveZers(cp);
        res = min(res, cand);
    }
    return res;
}

int Solve1(string s, int a, int b)
{
    int res = Inf;
    for (int i = 0; i < s.length(); i++) if (s[i] - '0' == b) {
        string cp = s;
        int cand = 0;
        for (int j = i; j + 1 < s.length(); j++) { swap(cp[j], cp[j + 1]); cand++; }
        cand += Solve2(cp, a);
        res = min(res, cand);
    }
    return res;
}

int main()
{
    cin >> s;
    int res = min(min(Solve1(s, 0, 0), Solve1(s, 2, 5)),
                  min(Solve1(s, 5, 0), Solve1(s, 7, 5)));
    printf("%d\n", res >= Inf? -1: res);
    return 0;
}