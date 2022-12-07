#include <cstdio>
const int P = 1e9 + 7;
int x, y;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i ++)
    {
        if(i & 1) x = (x + y + 1) % P;
        else y = (x + y + 1) % P;
    }
    printf("%d\n",(x + y) % P);
    return 0;
}