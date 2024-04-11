#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 505;

int n, m;
string s;
vector <ii> seq;

int Ask(const string &s)
{
    printf("? %s\n", s.c_str()); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

int main()
{
    scanf("%d %d", &n, &m);
    s.resize(m, '0');
    for (int i = 0; i < m; i++) {
        s[i] = '1';
        int got = Ask(s);
        s[i] = '0';
        seq.push_back(ii(got, i));
    }
    sort(seq.begin(), seq.end());
    int cur = 0;
    for (int i = 0; i < seq.size(); i++) {
        int ind = seq[i].second;
        s[ind] = '1';
        int got = Ask(s);
        if (cur + seq[i].first == got) {
            cur += seq[i].first;
            continue;
        }
        s[ind] = '0';
    }
    printf("! %d\n", cur); fflush(stdout);
    return 0;
}