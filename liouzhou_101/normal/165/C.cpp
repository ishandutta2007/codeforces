#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int k,len;
char s[1000010];
int F[1000010];

int main()
{
    scanf("%d",&k);
    scanf("%s",s+1);
    len=strlen(s+1);
    for (int i=1;i<=len;++i)
        F[i]=F[i-1]+s[i]-48;
    int L=0,R=0;
    long long ans=0;
    for (int i=1;i<=len;++i)
    {
        while (F[i]-F[L]>k) ++L;
        while (F[i]-F[R]>=k)
        {
            ++R;
            if (R>=i) break;
        }
        ans+=(R-L);
    }
    cout<<ans<<endl;
    return 0;
}