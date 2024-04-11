#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
    int n; cin >> n;
    cin >> s;
    for (int i = 0; i + 1 < s.length(); i++)
        if (s[i] > s[i + 1]) {
            printf("YES\n");
            printf("%d %d\n", i + 1, i + 2);
            return 0;
        }
    printf("NO\n");
    return 0;
}