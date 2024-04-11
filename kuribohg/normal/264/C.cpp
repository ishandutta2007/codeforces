#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=100010;
const LL INF=1000000000000000000LL;
int n,Q;
LL v[MAXN],c[MAXN],f[MAXN],A,B,fm[MAXN],ans,s1,s2;
bool cmp(int i,int j)
{
    return fm[i]>fm[j];
}
int main()
{
    scanf("%d%d",&n,&Q);
    for(int i=1;i<=n;i++) scanf("%I64d",&v[i]);
    for(int i=1;i<=n;i++) scanf("%I64d",&c[i]);
    if(n==1)
    {
        while(Q--)
        {
            scanf("%I64d%I64d",&A,&B);
            printf("%I64d\n",max(0LL,B*v[1]));
        }
        return 0;
    }
    while(Q--)
    {
        scanf("%I64d%I64d",&A,&B);
        for(int i=1;i<=n;i++) f[i]=-INF;
        for(int i=1;i<=n;i++) fm[i]=-INF;
        s1=1,s2=2;
        for(int i=1;i<=n;i++)
        {
            f[i]=max(f[i],B*v[i]);
            f[i]=max(f[i],fm[c[i]]+A*v[i]);
            int sub=s1;
            if(sub==c[i]) sub=s2;
            f[i]=max(f[i],fm[sub]+B*v[i]);
            if(f[i]>fm[c[i]])
            {
                fm[c[i]]=f[i];
                int s[3];
                s[0]=s1,s[1]=s2,s[2]=c[i];
                if(!cmp(s[0],s[1])) swap(s[0],s[1]);
                if(!cmp(s[0],s[2])) swap(s[0],s[2]);
                if(!cmp(s[1],s[2])) swap(s[1],s[2]);
                s1=s[0];
                s2=(s[1]==s[0])?s[2]:s[1];
            }
        }
        LL con=0;
        for(int i=1;i<=n;i++) con=max(con,f[i]);
        printf("%I64d\n",con);
    }
    return 0;
}