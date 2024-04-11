#include <bits/stdc++.h>
using namespace std;

const int Maxn = 52;
const string spec = "abacaba";

int T;
int n;
string s;
string cand;

bool Check(int ind)
{
    for (int i = 0; i < spec.length(); i++)
        if (s[ind + i] != '?' && s[ind + i] != spec[i])
            return false;
    return true;
}

int Count(const string &cand)
{
    int res = 0;
    for (int i = 0; i + spec.length() <= cand.length(); i++)
        res += cand.substr(i, spec.length()) == spec;
    return res;
}

bool Solve()
{
    for (int i = 0; i + spec.length() <= s.length(); i++)
        if (Check(i)) {
            cand = s;
            for (int j = 0; j < spec.length(); j++)
                cand[i + j] = spec[j];
            for (int j = 0; j < i; j++)
                cand[j] = cand[j] == '?'? 'd': cand[j];
            for (int j = i + spec.length(); j < s.length(); j++)
                cand[j] = cand[j] == '?'? 'd': cand[j];
            if (Count(cand) == 1) return true;
        }
    return false;
}

int main()
{
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s;
        if (Solve()) {
            printf("Yes\n");
            printf("%s\n", cand.c_str());
        } else printf("No\n");
    }
    return 0;
}