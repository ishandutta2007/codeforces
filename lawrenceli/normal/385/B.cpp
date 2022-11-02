#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <cstring>

using namespace std;

const int MAXN = 5500;

char s[MAXN];
int n, ans;
bool good[MAXN];

string substr(int i) {
    string ret = "";
    for (int j=i; j<i+4; j++)
        ret += s[j];

    return ret;
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    scanf("%s", s); n = strlen(s);

    memset(good, 0, sizeof(good));

    for (int i=0; i<n-3; i++)
        if (substr(i) == "bear") good[i] = 1;

    for (int i=0; i<n; i++) {
        for (int j=i+3; j<n; j++) {
            if (good[j-3]) {
                ans += n - j;
                break;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}