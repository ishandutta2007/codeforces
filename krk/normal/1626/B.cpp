#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
char tmp[Maxn];
string s;

void Read(string &s)
{
    scanf("%s", tmp); s = tmp;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        Read(s);
        bool done = false;
        for (int i = int(s.length()) - 2; i >= 0 && !done; i--) {
            int sum = int(s[i] - '0') + int(s[i + 1] - '0');
            if (sum >= 10) {
                s[i] = sum / 10 + '0';
                s[i + 1] = sum % 10 + '0';
                done = true; 
            } 
        }
        if (!done) {
            s[1] += s[0] - '0';
            s = s.substr(1);
        }
        printf("%s\n", s.c_str());
    }
    return 0;
}