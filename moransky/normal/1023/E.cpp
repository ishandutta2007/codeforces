#include <cstdio>
#include <iostream>
using namespace std;
const int N = 505;
int n, tot = 0;
char s[N << 1];
bool ask(int a, int b, int c, int d) {
    printf("? %d %d %d %d\n", a, b, c, d);
    fflush(stdout);
    char str[5]; scanf("%s", str);
    return str[0] == 'Y';
}
int main() {
    scanf("%d", &n);
    int x = 1, y = 1, cnt = n - 1;
    for(int i = 1; i <= cnt; i++) {
        if(x == n) 
            s[++tot] = 'R', y++;
        else if(y == n) 
            s[++tot] = 'D', x++;
        else {
            if(ask(x, y + 1, n, n)) s[++tot] = 'R', y++;
            else s[++tot] = 'D', x++;
        }
    }
    
    x = n, y = n;
    for(int i = 1; i <= cnt; i++) {
        if(x == 1)
            s[++tot] = 'R', y--;
        else if(y == 1) s[++tot] = 'D', x--;
        else {
            if(ask(1, 1, x - 1, y)) s[++tot] = 'D', x--;
            else s[++tot] = 'R', y--;
        }
    }
    printf("! ");
    for(int i = 1; i <= cnt; i++)
        putchar(s[i]);
    for(int i = cnt * 2; i > cnt; i--)
        putchar(s[i]);
    return 0;
}