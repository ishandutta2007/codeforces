#include<bits/stdc++.h>
using namespace std;
long long outp=1e18+42;
int primes[15]={2,3,5,7,11,13,17,19,21,23,29};
bool can(long long number,int a,int b)//number*(a^b)<=outp?
{
long long x=outp/number;
for(int i=1;i<=b;i++)x=x/a;
return x>=1;
}
long long my_pow(int a,int b)
{
long long c=1;
for(int i=1;i<=b;i++)c=c*a;
return c;
}
void rec(int divs,int position,int last_taken,long long number)
{
if(divs==1)
{
outp=min(outp,number);
return;
}
for(int i=1;i<divs&&i<=last_taken;i++)
    if(divs%(i+1)==0&&can(number,primes[position],i))
        rec(divs/(i+1),position+1,i,number*my_pow(primes[position],i));
}
int main()
{
int n;
cin>>n;
rec(n,0,n+1,1);
cout<<outp<<endl;
return 0;
}