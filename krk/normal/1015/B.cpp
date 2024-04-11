#include <bits/stdc++.h>
using namespace std;

int n;
string s, t;
vector <int> res;

int main()
{
    cin >> n;
    cin >> s;
    cin >> t;
    string a = s, b = t;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a != b) { printf("-1\n"); return 0; }
    for (int i = 0; i < t.length(); i++) {
        int pnt = i;
        while (s[pnt] != t[i]) pnt++;
        while (pnt > i) {
            res.push_back(pnt);
            swap(s[pnt - 1], s[pnt]);
            pnt--;
        }
    }
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    return 0;
}