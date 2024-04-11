#include <cstdio>
#include <algorithm>

using namespace std;

int t;
int n;
char s[105];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int ans = n;
        scanf(" %s", s);
        if (s[0] == '>' || s[n - 1] == '<') printf("0\n");
        else {
            char prev = '<'; int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == prev) cnt++;
                else {
                    ans = min(ans, cnt);
                    break;
                }
            }
            ans = min(cnt, ans);
            prev = '>', cnt = 0;
            for (int i = n - 1; i >= 0; i--) {
                if (s[i] == prev) cnt++;
                else {
                    ans = min(ans, cnt);
                    break;
                }
            }
            ans = min(cnt, ans);
            printf("%d\n", ans);
        }
    }
    return 0;
}