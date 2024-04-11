#include<stdio.h>
#include<iostream>
using namespace std;
long long int p,o,w,q,la,ra,ta,lb,rb,tb,d,lad,rad,lbd,rbd,d1,d2,e,maxi,i;
long long int a[5];
int gcd(long long int q,long long int w)
{
    p=q%w;
    if(p==0)
    {
        o=w;
    }
    else if(p==1)
    {
        o=1;
    }
    else
    {
        o=gcd(w,p);
    }
    return o;
}
int mini(long long int q,long long int w)
{
    if(q>w)
    {
        return w;
    }
    else{return q;}
}
int main(){
    cin>>la>>ra>>ta>>lb>>rb>>tb;
    if(ta>tb)
    {
        d = gcd(ta,tb);
    }
    if(ta<=tb)
    {
        d = gcd(tb,ta);
    }
    lad=la%d;
    rad=ra%d;
    lbd=lb%d;
    rbd=rb%d;
    d1=ra-la+1;
    d2=rb-lb+1;
    e=lad-lbd;
    e=e%d;
    e=e+d;
    e=e%d;
    a[1]=mini(d2-e,d1);
    e=(((lbd-lad)%d)+d)%d;
    a[2]=mini(d1-e,d2);
    e=(((rad-rbd)%d)+d)%d;
    a[3]=mini(d1-e,d2);
    e=(((rbd-rad)%d)+d)%d;
    a[4]=mini(d2-e,d1);
    maxi=a[1];
    for(i=2;i<=4;i++)
    {
        if(a[i]>maxi)
        {
            maxi=a[i];
        }
    }
    if(maxi>0)
    cout<<maxi;
    else
        cout<<0;
}