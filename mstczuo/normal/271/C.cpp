# include <iostream>
# include <cstdio>
using namespace std;

int n,k;
int main()
{
    cin >> n >> k;
    if(n<3*k){printf("-1\n");return 0;}
    for(int i=1;i<=k;i++)
        printf("%d ",i);
    for(int i=1;i<=k;i++)
        printf("%d ",i);
    for(int i=2;i<=k;i++)
        printf("%d ",i);
    for(int i=(k*3);i<=n;i++)
        printf("1 ");
    return 0;
}