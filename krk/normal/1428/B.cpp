#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

bool ret[Maxn];
int T;
int n;
string s;

int main()
{
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s;
        fill(ret, ret + n, false);
        bool mor = true, les = true;
        for (int i = 0; i < n; i++)
            if (s[i] == '-') {
                ret[i] = ret[(i + 1) % n] = true;
            } else if (s[i] == '<') mor = false;
              else les = false;
        if (mor || les) printf("%d\n", n);
        else {
            int res = 0;
            for (int i = 0; i < n; i++)
                res += ret[i];
            printf("%d\n", res);
        }
    }
    return 0;
}