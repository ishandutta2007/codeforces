#include <bits/stdc++.h>
using namespace std;

const int Maxn = 205;

int n;
string my[Maxn];
map <string, int> M, tmp;
vector <string> best;
set <string> pref;
string res;

bool Solve(string a, string b)
{
    for (int i = 1; i < a.length(); i++)
        if (a[i] != b[i - 1]) return false;
    a += string(1, b[int(b.length()) - 1]);
    tmp.clear();
    for (int i = 1; i < a.length(); i++) {
        tmp[a.substr(0, i)]++;
        tmp[a.substr(int(a.length()) - i)]++;
    }
    if (M == tmp) {
        res = a;
        return true;
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < 2 * n - 2; i++) {
        string s; cin >> s;
        my[i] = s;
        M[s]++;
        if (!best.empty() && s.length() > best[0].length())
            best.clear();
        if (best.empty() || s.length() == best[0].length())
            best.push_back(s);
    }
    Solve(best[0], best[1]);
    Solve(best[1], best[0]);
    for (int i = 0; i < 2 * n - 2; i++)
        if (res.substr(0, my[i].length()) == my[i] && pref.find(my[i]) == pref.end()) {
            printf("P"); pref.insert(my[i]);
        } else printf("S");
    printf("\n");
    return 0;
}