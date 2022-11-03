#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T,n,s;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&s);
        printf("%d\n",s/((n+2)/2));
    }
    return 0;
}