#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void read(int &digit)
{
    digit=0;
    char c;
    for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
    bool type=false;
    if (c=='-')
        type=true,c=getchar();
    for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
    if (type==true)
        digit=-digit;
}

#define maxn 310
int n;
int a[maxn];
bool b[maxn][maxn];
int f[maxn];
int c[maxn];
int que[maxn];

int fa(int t)
{
    if (f[t]==t)    return t;
    return f[t]=fa(f[t]);
}
void Union(int a,int b)
{
    a=fa(a),b=fa(b);
    f[a]=b;
}
int main()
{
    read(n);
    for (int i=1;i<=n;i++)  f[i]=i;
    for (int i=1;i<=n;i++)  read(a[i]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            char ch=getchar();
            while (ch!='0' && ch!='1')  ch=getchar();
            if (ch=='1')    b[i][j]=true,Union(i,j);
        }
    
    for (int i=1;i<=n;i++)
    if (c[i]==0)
    {
        int cnt=0;
        for (int j=1;j<=n;j++)
        if (fa(j)==fa(i))
            que[++cnt]=a[j];
        sort(que+1,que+cnt+1);
        int lbn=1;
        for (int j=1;j<=n;j++)
        if (fa(j)==fa(i))
            c[j]=que[lbn++];
    }
    for (int i=1;i<=n;i++)  printf("%d ",c[i]);
    printf("\n");
    return 0;
}