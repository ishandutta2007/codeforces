#include <bits/stdc++.h>
using namespace std;

int has[2];

int Ask(const string &s)
{
    printf("%s\n", s.c_str());
    fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

int main()
{
    int g = Ask(string(300, 'a'));
    if (g == 0) return 0;
    has[0] = 300 - g;
    g = Ask(string(300, 'b'));
    if (g == 0) return 0;
    has[1] = 300 - g;
    string res;
    while (true)
        if (has[0] == 0) { res += string(has[1], 'b'); break; }
        else if (has[1] == 0) { res += string(has[0], 'a'); break; }
        else {
            string cand = res + string(1, 'a') + string(has[0] + has[1] - 1, 'b');
            g = Ask(cand);
            if (g == 0) return 0;
            if (g == has[0] - 1) { res += string(1, 'a'); has[0]--; }
            else { res += string(1, 'b'); has[1]--; }
        }
    Ask(res);
    return 0;
}