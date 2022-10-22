#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 2005;

char tmp[Maxn];
int t;
int n, k;
string s;
char nd[Maxn];
int nlen;

void Read(string &s)
{
    scanf("%s", tmp);
    s = tmp;
}

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        Read(s);
        vector <ii> res;
        nlen = 0;
        for (int i = 0; i < k - 1; i++) {
            nd[nlen++] = '(';
            nd[nlen++] = ')';
        }
        nd[nlen++] = '(';
        while (nlen + 3 <= n) {
            nd[nlen++] = '(';
            nd[nlen++] = ')';
        }
        nd[nlen++] = ')';
        for (int i = 0; i < n; i++)
            if (nd[i] != s[i]) {
                int pnt = i + 1;
                while (nd[i] != s[pnt]) pnt++;
                res.push_back(ii(i, pnt));
                reverse(s.begin() + i, s.begin() + pnt + 1);
            }
        printf("%d\n", int(res.size()));
        for (int i = 0; i < res.size(); i++)
            printf("%d %d\n", res[i].first + 1, res[i].second + 1);
    }
    return 0;
}