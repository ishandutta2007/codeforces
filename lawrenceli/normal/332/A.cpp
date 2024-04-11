#include <cstdio>
#include <cstring>
int n, len, best;
char str[2005];
int main() {
    scanf("%d%s", &n, str); len = strlen(str);
    for (int i=n; i<len; i+=n) {
        if (str[i-1] == str[i-2] && str[i-2] == str[i-3]) best++;
    }
    printf("%d\n", best);
}