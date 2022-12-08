#include <stdio.h>

int day[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
int st = 4;

int main()
{
    int x; char s[10];
    scanf ("%d %*s %s",&x,s);
    int a = 0;
    if (s[0] == 'w'){
        x--;
        for (int i=1;i<=12;i++){
            for (int k=0;k<day[i];k++){
                if (st == x) a++;
                st = (st + 1) % 7;
            }
        }
    }
    else{
        for (int i=1;i<=12;i++) if (x <= day[i]) a++;
    }
    printf ("%d\n",a);
    return 0;
}