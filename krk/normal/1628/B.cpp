#include <bits/stdc++.h>
using namespace std;

const int Maxl = 10;
const int Maxn = 100005;

char tmp[Maxl];
int T;
int n;
string s[Maxn];
set <string> twos, threes;

void Read(string &s)
{
    scanf("%s", tmp);
    s = tmp;
}

bool Solve()
{
    twos.clear(); threes.clear();
    for (int i = 0; i < n; i++) {
        string cp = s[i];
        reverse(cp.begin(), cp.end());
        if (s[i] == cp) return true;
        if (s[i].length() == 2) {
            if (twos.find(cp) != twos.end() || threes.find(cp) != threes.end()) return true;
            twos.insert(s[i]);
        } else {
            if (threes.find(cp) != threes.end()) return true;
            if (twos.find(cp.substr(0, 2)) != twos.end()) return true;
            threes.insert(s[i]);
            threes.insert(s[i].substr(0, 2));
        }
    }
    return false;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            Read(s[i]);
        printf("%s\n", Solve()? "YES": "NO");
    }
    return 0;
}