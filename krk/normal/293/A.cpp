#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int n;
string s, t;
int cnt[4];
int res[2];

int main()
{
    cin >> n;
    cin >> s >> t;
    for (int i = 0; i < 2 * n; i++)
        if (s[i] == '1' && t[i] == '1') cnt[0]++;
        else if (s[i] == '1' && t[i] == '0') cnt[1]++;
        else if (s[i] == '0' && t[i] == '1') cnt[2]++;
        else if (s[i] == '0' && t[i] == '0') cnt[3]++;
    int cur = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (cur == 0)
            if (cnt[0]) { cnt[0]--; res[0]++; }
            else if (cnt[1]) { cnt[1]--; res[0]++; }
            else if (cnt[2]) cnt[2]--;
            else cnt[3]--;
        else if (cnt[0]) { cnt[0]--; res[1]++; }
             else if (cnt[2]) { cnt[2]--; res[1]++; }
             else if (cnt[1]) cnt[1]--;
             else cnt[3]--;
        cur = 1 - cur;
    }
    if (res[0] > res[1]) printf("First\n");
    else if (res[0] == res[1]) printf("Draw\n");
    else printf("Second\n");
    return 0;
}