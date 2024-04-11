#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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

int n,m,q;
#define maxn 510
bool b[maxn][maxn];
int sumn[maxn][maxn],summ[maxn][maxn];
int main()
{
    read(n),read(m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            char ch=getchar();
            while (ch!='.' && ch!='#')  ch=getchar();
            if (ch=='.')    b[i][j]=true;else b[i][j]=false;
        }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            sumn[i][j]=sumn[i][j-1];
            if (b[i][j] && b[i][j-1])   sumn[i][j]++;
        }
    }
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
        {
            summ[i][j]=summ[i][j-1];
            if (b[j][i] && b[j-1][i])   summ[i][j]++;
        }
    }
    read(q);
    for (int i=1;i<=q;i++)
    {
        int x1,x2,y1,y2;
        read(x1),read(y1),read(x2),read(y2);
        if (x1>x2)  swap(x1,x2);
        if (y1>y2)  swap(y1,y2);
        int ans=0;
        for (int j=x1;j<=x2;j++)
            ans+=sumn[j][y2]-sumn[j][y1];
        for (int j=y1;j<=y2;j++)
            ans+=summ[j][x2]-summ[j][x1];
        printf("%d\n",ans);
    }
    return 0;
}