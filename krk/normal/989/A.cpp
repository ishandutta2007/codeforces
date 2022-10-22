#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
    cin >> s;
    for (int i = 0; i + 3 <= s.length(); i++) {
        auto tmp = s.substr(i, 3);
        sort(tmp.begin(), tmp.end());
        if (tmp == "ABC") {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}