#include<bits/stdc++.h>
using namespace std;

int n,p0,p1,v;

int ask(string s)
{
    printf("? ");
    for(int i=0;i<s.length();i++)printf("%c",s[i]);
    printf("\n");fflush(stdout);
    int x;
    scanf("%d",&x);
    return x;
}



int main()
{
    scanf("%d",&n);
    string t="";
    for(int i=1;i<=n;i++)t+='1';
    int a1=ask(t);
    t="0";
    for(int i=1;i<n;i++)t+='1';
    int a2=ask(t);
    if(a1<a2)p1=1,v=0;else p0=1,v=1;
    int l=2,r=n;
    while(r-l>=1)
    {
        int mid=(l+r)>>1;
        if(v==0)
        {
            t="";
            for(int i=1;i<l;i++)t+='1';
            for(int i=l;i<=mid;i++)t+='0';
            for(int i=mid+1;i<=n;i++)t+='1';
            int now=ask(t);
            if(now-a1>=mid-l+1)l=mid+1;else r=mid;
        }else
        {
            t="";
            for(int i=1;i<l;i++)t+='1';
            for(int i=l;i<=mid;i++)t+='0';
            for(int i=mid+1;i<=n;i++)t+='1';
            int now=ask(t);
            if(a1-now>=mid-l+1)l=mid+1;else r=mid;
        }
    }
    if(p0==0)p0=l;else p1=l;
    printf("! %d %d\n",p0,p1);
    fflush(stdout);
    return 0;
}