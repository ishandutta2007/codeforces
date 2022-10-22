#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxl = 1000005;
const int Maxn = 100005;
const string wovs = "aeoiu";

char tmp[Maxl];
int n;
vector <string> cnt[Maxl];
vector <string> spec[Maxl][10];
vector <string> both, one;

void Read(string &s)
{
    scanf("%s", tmp); s = tmp;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        string s; Read(s);
        int lst = -1, got = 0;
        for (int j = 0; j < s.length(); j++) {
            int ind = wovs.find(s[j]);
            if (ind != string::npos) {
                got++; lst = ind;
            }
        }
        cnt[got].push_back(s);
        spec[got][lst].push_back(s);
    }
    for (int i = 0; i < Maxl; i++) {
        vector <string> tmp;
        for (int j = 0; j < 10; j++) {
            while (spec[i][j].size() >= 2) {
                both.push_back(spec[i][j].back());
                spec[i][j].pop_back();
                both.push_back(spec[i][j].back());
                spec[i][j].pop_back();
            }
            if (spec[i][j].size() >= 1)
                tmp.push_back(spec[i][j].back());
        }
        while (tmp.size() >= 2) {
            one.push_back(tmp.back());
            tmp.pop_back();
            one.push_back(tmp.back());
            tmp.pop_back();
        }
    }
    while (both.size() > one.size()) {
        one.push_back(both.back());
        both.pop_back();
    }
    int my = int(both.size()) / 2;
    printf("%d\n", my);
    for (int i = 0; i < my; i++) {
        printf("%s %s\n", one[2 * i].c_str(), both[2 * i].c_str());
        printf("%s %s\n", one[2 * i + 1].c_str(), both[2 * i + 1].c_str());
    }
    return 0;
}