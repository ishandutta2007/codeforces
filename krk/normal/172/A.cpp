#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int Maxn = 30005;

int n;
string s[Maxn];

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    int len = 1;
    while (len <= s[0].length()) {
        string a = s[0].substr(0, len);
        int i = 1;
        while (i < n)
            if (a == s[i].substr(0, len)) i++;
            else break;
        if (i == n) len++;
        else break;
    }
    cout << len - 1 << endl;
    return 0;
}