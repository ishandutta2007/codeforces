#include<bits/stdc++.h>
using namespace std;
int l,r;
long long ans=0;
void test(int x)
{
    if(l>x||x>r)return;
    long long v=9;
    while(v<x)
    {
        v=v*10+9;
    }
    ans=max(ans,1LL*x*(v-x));
}
int main()
{
scanf("%i%i",&l,&r);
test(l);
test(r);

long long p=4,q=5;
while(p<=1e9)
{
    test(p);
    test(q);
    p=p*10+9;
    q=q*10;
}

printf("%lld\n",ans);
return 0;
}