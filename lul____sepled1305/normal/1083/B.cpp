#include<bits/stdc++.h>
using namespace std;
int n,k,l,r,g;
long long ss,s;
char a[500005], b[500005];
int main()
{
    ss=0;
    scanf("%d%d",&n,&k);
    scanf("%s%s",&a,&b);
    if(a[0]==b[0])
    {
        ss=1;
    }
    else
    {
        if(k==1)
            ss=1;
        else
            ss=2;
    }
    s=ss;
    for(l=1;l<=n-1;l++)
    {
        if(a[l]=='a' && b[l]=='a')
        {
            r=0;
        }
        if(a[l]=='b' && b[l]=='b')
        {
            r=0;
        }
        if(a[l]=='a' && b[l]=='b')
        {
            r=1;
        }
        if(a[l]=='b' && b[l]=='a')
        {
            r=-1;
        }
        if(s*2+r-2<k)
        {
            s=s*2+r-1;
            if(s<=0)
            {
                s=1;
            }
        }
        else
        {
            s=k;
        }
        ss+=s;
        //cout<<l<<"             "<<ss<<k<<"\n";
    }
    printf("%lld",ss);
    return 0;
}