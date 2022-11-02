#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

char str[11], ok[2];
int n, number, L, R;

int main(){
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    L = - 2 * 1000000000;
    R = -L;
    scanf("%d", &n);
    for (; n--;)
    {
        scanf("%s%d%s", str, &number, ok);
        if (strlen(str) == 1)
           if (str[0] == '<')
              if (ok[0] == 'Y') R = min(R, number - 1);
              else L = max(L, number);
           else if (ok[0] == 'Y') L = max(L, number + 1);
                else R = min(R, number);
        else 
           if (str[0] == '<')
              if (ok[0] == 'Y') R = min(R, number);
              else L = max(L, number + 1);
           else if (ok[0] == 'Y') L = max(L, number);
                else R = min(R, number - 1);
    }
        if (L > R) printf("Impossible\n");
        else printf("%d\n", L);
}