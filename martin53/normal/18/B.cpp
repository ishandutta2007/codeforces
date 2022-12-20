#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,d,m,l;
scanf("%i%i%i%i",&n,&d,&m,&l);
long long where=0;
for(int k=1;k<=n;k++)
{
    long long le=1LL*(k-1)*m,ri=1LL*(k-1)*m+l;
    if(where<le)
    {
        printf("%I64d\n",where);
        return 0;
    }
    long long p=ri+1-where;
    where=where+(p+d-1)/d*d;
}
printf("%I64d\n",where);
return 0;
}