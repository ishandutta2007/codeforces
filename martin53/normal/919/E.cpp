#include<bits/stdc++.h>
using namespace std;
const int pmax=1e6+42;
int a,b,p;
long long x;
int when[pmax];
int my_pow(int a,int b)
{
    if(b==0)return 1;
    int c=my_pow(a,b/2);
    if(b%2==0)return 1LL*c*c%p;
    return 1LL*c*c%p*a%p;
}
int main()
{
scanf("%i%i%i%lld",&a,&b,&p,&x);
memset(when,-1,sizeof(when));
long long value=1;
int cycle=0;
while(when[value]==-1)
{
    when[value]=cycle;
    cycle++;
    value=value*a%p;
}
long long ans=0;
for(int j=1;j<p&&j<=x;j++)
{
    long long c=b;
    c=c*my_pow(j,p-2)%p;
    c=c*my_pow(my_pow(a,j),p-2)%p;
    //cout<<j<<" -> "<<c<<endl;
    if(when[c]==-1)continue;
    long long i_max=(x-j)/p;
    if(when[c]>i_max)continue;
    ans=ans+(i_max-when[c])/cycle+1;
}
printf("%lld\n",ans);
return 0;
}