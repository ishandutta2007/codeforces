#include<bits/stdc++.h>
using namespace std;
int y1=0,y2;
int t1,t2,t0;
void test(int n1,int n2)
{
    long long p=1LL*t1*n1+1LL*t2*n2-1LL*t0*(n1+n2);
    long long q=n1+n2;

    long long s=1LL*t1*y1+1LL*t2*y2-1LL*t0*(y1+y2);
    long long t=y1+y2;

    if(p*t<s*q)
    {
        y1=n1;
        y2=n2;
    }
    else if(p*t==s*q)
    {
        if(y1+y2<n1+n2)
        {
            y1=n1;
            y2=n2;
        }
    }
}
int main()
{
int x1,x2;
scanf("%i%i%i%i%i",&t1,&t2,&x1,&x2,&t0);

if(t1==t0&&t2==t0)
{
    printf("%i %i\n",x1,x2);
    return 0;
}
if(t1==t0)
{
    printf("%i %i\n",x1,0);
    return 0;
}
if(t2==t0)
{
    printf("%i %i\n",0,x2);
    return 0;
}


y2=x2;
for(int y_1_now=1;y_1_now<=x1;y_1_now++)
{
    long long p=t2-t0;
    if(p==0)continue;
    long long q=1LL*(t0-t1)*y_1_now;

    if(q/p>x2)continue;

    int y_2_now=(q+p-1)/p;
    if(y_2_now>x2)continue;

    //cout<<y_1_now<<" "<<y_2_now<<endl;

    test(y_1_now,y_2_now);
}
printf("%i %i\n",y1,y2);
return 0;
}