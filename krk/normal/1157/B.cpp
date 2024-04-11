#include <bits/stdc++.h>
using namespace std;

const int Maxd = 10;

int n;
string s;
int f[Maxd];

int main()
{
    cin >> n;
    cin >> s;
    for (int i = 1; i < Maxd; i++)
        scanf("%d", &f[i]);
    for (int i = 0; i < s.length(); i++) {
        int dig = s[i] - '0';
        if (f[dig] > dig) {
            for (int j = i; j < s.length(); j++) {
                int cur = s[j] - '0';
                if (f[cur] >= cur) s[j] = f[cur] + '0';
                else break;
            }
            break;
        }
    }
    cout << s << endl;
    return 0;
}