#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int MaxN=1<<11;

int n;
char s[MaxN];
int v[MaxN<<1];
int F[MaxN][MaxN];

void add(int k,int L,int R,int x,int y)
{
    if (L==x&&R==y)
    {
        ++v[k];
        return;
    }
    int mid=(L+R)>>1;
    if (y<=mid)
        add(k<<1,L,mid,x,y);
    else if (x>mid)
        add((k<<1)|1,mid+1,R,x,y);
    else
    {
        add(k<<1,L,mid,x,mid);
        add((k<<1)|1,mid+1,R,mid+1,y);
    }
}

long long get(int x)
{
    long long tmp=0;
    for (int k=x+MaxN-1;k>=1;k>>=1)
        tmp+=v[k];
    return tmp;
}

int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    for (int i=1;i<=n;++i)
    {
        int L=i,R=i;
        add(1,1,MaxN,1,L);
        F[L][R]=1;
        while (1)
        {
            if (L==1||R==n) break;
            --L;
            ++R;
            if (s[L]!=s[R]) break;
            add(1,1,MaxN,1,L);
            F[L][R]=1;
        }
    }
    for (int i=1;i<n;++i)
    {
        int L=i,R=i+1;
        if (s[L]!=s[R]) continue;
        add(1,1,MaxN,1,L);
        F[L][R]=1;
        while (1)
        {
            if (L==1||R==n) break;
            --L;
            ++R;
            if (s[L]!=s[R]) break;
            add(1,1,MaxN,1,L);
            F[L][R]=1;
        }
    }
    long long ans=0;
    for (int i=1;i<=n;++i)
        for (int j=i;j<n;++j)
            if (F[i][j])
                ans+=get(j+1);
    cout<<ans<<endl;
    return 0;
}