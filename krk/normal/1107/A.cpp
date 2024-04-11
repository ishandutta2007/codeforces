#include <bits/stdc++.h>
using namespace std;

int q;
int n;
string s;

int main()
{
    cin >> q;
    while (q--) {
        cin >> n;
        cin >> s;
        if (s.length() == 2 && s[0] >= s[1])
            printf("NO\n");
        else {
            printf("YES\n");
            printf("2\n");
            printf("%c ", s[0]);
            for (int i = 1; i < s.length(); i++)
                printf("%c", s[i]);
            printf("\n");
        }
    }
    return 0;
}