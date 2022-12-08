#include <stdio.h>

int sq[1000001];

int main()
{
    int a,b;

    scanf ("%d %d",&a,&b);

    for (int i=0;i<=1000;i++) sq[i*i] = i;
    for (int ax=a;ax>=-a;ax--){
        if (ax == 0) continue;
        int ay = a * a - ax * ax;
        if (ay = sq[ay]){
            for (int bx=b;bx>=-b;bx--){
                int by = b * b - bx * bx;
                if (by = sq[by]){
                    if (ax * bx + ay * by == 0 && ax != bx && ay != by){
                        puts("YES");
                        printf ("0 0\n%d %d\n%d %d\n",ax,ay,bx,by);
                        return 0;
                    }
                }
            }
        }
    }
    puts("NO");

    return 0;
}