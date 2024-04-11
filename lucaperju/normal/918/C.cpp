#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;
long long cmmdc(long long a,long long b)
{
    long long r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
long long lgput (long long cnt, long long mod,long long put)
{
    long long r=1,p=put;
    if(cnt==0)
        return 1;
    while(cnt>1)
    {
        if(!(cnt&1))
        {
            p=p*1LL*p%mod;
            cnt>>=1;
        }
        else
        {
            --cnt;
            r=r*1LL*p%mod;
        }
    }
    p=p*1LL*r;
    return p%mod;
}
/*
for(i=1;i<=n;++i)
*/
char v[50005];
int mn[50005],mx[50005];
int main()
{
    long long t,i,j=0,n,c,dif,ok,rad,s=0,x,k,jdr=1,d,a,b,y,pls,mns,egl;
    cin>>(v+1);
    n=strlen((v+1));
    for(i=1;i<=n;++i)
    {
        mn[i]=mx[i]=mx[i-1]=mn[i-1]=0;
        if(v[i]!=')')
        for(j=i;j<=n;j++)
        {
            if(v[j]=='(')
            {
                mx[j]=mx[j-1]+1;
                mn[j]=mn[j-1]+1;
            }
            else
            if(v[j]==')')
            {
                mx[j]=mx[j-1]-1;
                mn[j]=mn[j-1]-1;
            }
            else
            {
                mx[j]=mx[j-1]+1;
                mn[j]=mn[j-1]-1;
            }
            mn[j]=max(0,mn[j]);
            if(mx[j]<0)
                break;
            if((j-i+1)%2==0 && mn[j]==0)
                ++s;
         /*   pls=mns=egl=0;
            if(v[j]!='?' && v[j-1]!='?')
            {
                if(v[j-1]==')' && mx[j-2]<=0)
                    break;
                if(v[j]!=v[j-1])
                    egl=1;
                else if(v[j]=='(')
                    pls=1;
                else
                    mns=1;
            }
            else
            {
                if(v[j]==v[j-1])
                    pls=mns=egl=1;
                else if(v[j]=='(')
                {
                    pls=1;
                    if(mx[j-2]>0)
                    egl=1;
                }
                else if(v[j]==')')
                    egl=mns=1;
                else if(v[j-1]=='(')
                    pls=egl=1;
                else if(v[j-1]==')')
                {
                    if(mx[j-2]<=0)
                        break;
                    egl=mns=1;
                }
            }
            if(mns)
                mn[j]=mn[j-2]-2,mx[j]=mx[j-2]-2;
            if(pls)
            {
                mx[j]=mx[j-2]+2;
                if(!mns)
                    mn[j]=mn[j-2]+2;
            }
            if(egl)
            {
                if(!pls)
                    mx[j]=mx[j-2];
                if(!mns)
                    mn[j]=mn[j-2];
            }
            mn[j]=max(mn[j],0);
            mx[j]=max(mx[j],0);
            if(mn[j]<=0 && mx[j]>=0 && v[j]!='(')
                ++s;
            */
        }
    }
    cout<<s;
    return 0;
}