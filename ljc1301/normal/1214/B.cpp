#include <bits/stdc++.h>
using namespace std;
int main()
{
    int b,g,n;
    scanf("%d%d%d",&b,&g,&n);
    printf("%d\n",min(n,b)-max(0,n-g)+1);
    return 0;
}