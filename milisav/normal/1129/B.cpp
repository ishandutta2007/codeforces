#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    scanf("%d",&k);
    int n=1999;
    int mx=1000000;
    printf("2000\n");
    printf("-1 ");
    k=k+2000;
    for(int i=0;i<n;i++) {
        printf("%d ",min(mx,k));
        k-=min(mx,k);
    }
    return 0;
}