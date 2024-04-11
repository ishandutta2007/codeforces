#include <stdio.h>

int N,X,Y,Z;

int main()
{
    int x,y,z;
    for (scanf("%d",&N);N--;) scanf("%d%d%d",&x,&y,&z), X += x, Y += y, Z += z;
    puts(X||Y||Z?"NO":"YES");
}