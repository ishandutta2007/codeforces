#include <stdio.h>
#include <cstring>

using namespace std;

const int N = 200000;

int main() {
    int n, res = -1;
    char s[N];
    scanf("%d %s", &n, &s);
    for(int x, mx = -1, i = 0;i < n;i++) {
        scanf("%d", &x);
        if(s[i] == 'L') {
            if(mx != -1 && (res == -1 || res > (x - mx) / 2)) 
                res = (x - mx) / 2;
        }else mx = x;
    }
    
    printf("%d\n", res);
    
    return 0;
}