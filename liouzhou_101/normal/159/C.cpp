#include<cstdio>
#include<cstring>

const int MaxN=1<<18;

int k,n,len;
char s[MaxN];
int v[26][MaxN<<1];
int flag[MaxN];

void add(int c,int x,int p)
{
    for (int k=x+MaxN-1;k>=1;k>>=1)
        v[c][k]+=p;
}

int find(int c,int p)
{
    int k=1,L=1,R=MaxN;
    while (1)
    {
        int mid=(L+R)>>1;
        if (v[c][k<<1]>=p)
        {
            k<<=1;
            R=mid;
        }
        else
        {
            p-=v[c][k<<1];
            k=(k<<1)|1;
            L=mid+1;
        }
        if (L==R) break;
    }
    return L;
}

int main()
{
    scanf("%d%s%d",&k,s+1,&n);
    len=strlen(s+1);
    for (int i=1;i<k;++i)
        for (int j=1;j<=len;++j)
            s[j+len*i]=s[j];
    len*=k;
    for (int i=1;i<=len;++i)
        add(s[i]-'a',i,1);
    while (n--)
    {
        int p;
        char c[5];
        scanf("%d%s",&p,c);
        int x=find(c[0]-'a',p);
        flag[x]=1;
        add(c[0]-'a',x,-1);
    }
    for (int i=1;i<=len;++i)
        if (!flag[i]) putchar(s[i]);
    putchar('\n');
    return 0;
}