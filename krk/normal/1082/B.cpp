#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector <int> V;
int g;
int res;

void Clear()
{
    for (int i = 0; i < V.size(); i++) {
        res = max(res, V[i] + 1);
        if (i + 1 < V.size()) res = max(res, V[i] + V[i + 1] + 1);
    }
    V.clear();
}

int main()
{
    cin >> n;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        g += s[i] == 'G';
    for (int i = 0, j; i < s.length(); i = j) {
        j = i;
        while (j < s.length() && s[i] == s[j]) j++;
        if (s[i] == 'G') V.push_back(j - i);
        else if (j - i > 1) Clear();
    }
    Clear();
    printf("%d\n", min(g, res));
    return 0;
}