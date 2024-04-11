#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
vector<int> d[nmax];
int x_,p_,sum=0;
int rec(int pos,int value,int mult)
{
    if(pos==d[p_].size())return x_/value*mult;
    return rec(pos+1,value,mult)+rec(pos+1,value*d[p_][pos],-mult);
}
int take(int x,int p)
{
    sum=0;
    x_=x;
    p_=p;
    //cout<<x<<" "<<p<<" -> "<<rec(0,1,1)<<endl;
    return rec(0,1,1);
}
int main()
{
for(int i=2;i<nmax;i++)
    if(d[i].size()==0)
    {
        for(int j=i;j<nmax;j=j+i)
            d[j].push_back(i);
    }
int t,x,p,k;
scanf("%i",&t);
for(int i=1;i<=t;i++)
{
    scanf("%i%i%i",&x,&p,&k);
    k=k+take(x,p);
    int ok=(1<<23)-1,not_ok=1;
    while(ok-not_ok>1)
    {
        int av=(ok+not_ok)/2;
        if(take(av,p)>=k)ok=av;
        else not_ok=av;
    }
    printf("%i\n",ok);
}
return 0;
}