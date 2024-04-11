#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int Maxk = 15;

string s;
int k;
string p;
int res;

int main()
{
    getline(cin, s); s += ".";
    cin >> k;
    while (k--) {
        cin >> p;
        int cnt[2] = {0, 0};
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
            if (s[i] == p[0]) cnt[0]++;
            else if (s[i] == p[1]) cnt[1]++;
            else {
                if (p[0] == p[1]) ans += max(0, cnt[0] - 1);
                else ans += min(cnt[0], cnt[1]);
                cnt[0] = cnt[1] = 0;
            }
        res += ans;
    }
    cout << res << endl;
    return 0;
}