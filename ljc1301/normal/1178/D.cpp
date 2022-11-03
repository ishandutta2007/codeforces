#include <bits/stdc++.h>
using namespace std;
bool prime(int n)
{
    int i;
    if(n==1) return 0;
    for(i=2;i*(long long)i<=n;i++)
        if(!(n%i))
            return 0;
    return 1;
}
int main()
{
    int n,m,i;
    scanf("%d",&n);
    for(m=n;!prime(m);m++);
    printf("%d\n",m);
    for(i=1;i<=n;i++) printf("%d %d\n",i,i%n+1);
    for(i=1;i<=m-n;i++) printf("%d %d\n",i,n-i);
    return 0;
}