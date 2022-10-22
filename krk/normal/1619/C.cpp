#include <bits/stdc++.h>
using namespace std;

const int Maxl = 20;

char tmp[Maxl];
int T;
string a, s;
char b[Maxl];

void Read(string &s)
{
    scanf("%s", tmp);
    s = tmp;
}

bool Solve()
{
    int len = s.length();
    int pnt = 0;
    for (int i = int(a.length()) - 1; i >= 0; i--)
        if (len == 0) return false;
        else {
            int add = (int(s[len - 1] - '0') - int(a[i] - '0') + 10) % 10;
            int tot = int(a[i] - '0') + add;
            len--; tot /= 10;
            if (tot)
                if (len == 0 || s[len - 1] - '0' != tot) return false;
                else len--;
            b[pnt++] = add + '0';
        }
    while (len > 0) {
        b[pnt++] = s[len - 1];
        len--;
    }
    while (pnt > 1 && b[pnt - 1] == '0') pnt--;
    reverse(b, b + pnt);
    b[pnt] = '\0';
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        Read(a);
        Read(s);
        printf("%s\n", Solve()? b: "-1");
    }
    return 0;
}