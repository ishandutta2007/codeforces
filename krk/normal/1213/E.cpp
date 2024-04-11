#include <bits/stdc++.h>
using namespace std;

int n;
string a, b;

bool Check(string &s)
{
    for (int i = 0; i + 1 < s.length(); i++)
        if ((s[i] == a[0] && s[i + 1] == a[1]) ||
            (s[i] == b[0] && s[i + 1] == b[1])) return false;
    return true;
}

string Big(char a, char b, char c)
{
    return string(n, a) + string(n, b) + string(n, c);
}

string Small(char a, char b, char c)
{
    string s(3 * n, '?');
    for (int i = 0; i < n; i++) {
        s[3 * i] = a;
        s[3 * i + 1] = b;
        s[3 * i + 2] = c;
    }
    return s;
}

char Rem(char a, char b)
{
    if (a != 'a' && b != 'a') return 'a';
    if (a != 'b' && b != 'b') return 'b';
    return 'c';
}

int main()
{
    cin >> n;
    cin >> a >> b;
    for (char ch1 = 'a'; ch1 <= 'c'; ch1++)
        for (char ch2 = 'a'; ch2 <= 'c'; ch2++) if (ch1 != ch2)
            for (char ch3 = 'a'; ch3 <= 'c'; ch3++) if (ch1 != ch3 && ch2 != ch3) {
                string s = Big(ch1, ch2, ch3);
                if (Check(s)) {
                    printf("YES\n");
                    printf("%s\n", s.c_str());
                    return 0;
                }
                s = Small(ch1, ch2, ch3);
                if (Check(s)) {
                    printf("YES\n");
                    printf("%s\n", s.c_str());
                    return 0;
                }
            }
    printf("NO\n");
    return 0;
}