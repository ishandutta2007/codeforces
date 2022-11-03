#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++,printf("\n"))
        for(j=0;j<n;j++)
            printf("%d ",(i%(n/2)*(n/2)+j%(n/2))*4+(i/(n/2)*2+j/(n/2)));
    return 0;
}