#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n,pw[10],p[100010],len;
char a[100010][20];
bool ok=true;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%s",a[i]);
    pw[0]=1;
    for(int i=1;i<10;i++) pw[i]=pw[i-1]*10;
    for(int i=1;i<=n;i++)
    {
        len=strlen(a[i]);
        for(int j=len-1;j>=0;j--)
        {
            if(a[i][j]=='?') p[i]+=9*pw[len-j-1];
            else p[i]+=(a[i][j]-'0')*pw[len-j-1];
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(p[i]<=p[i-1]) {ok=false;break;}
        len=strlen(a[i]);
        for(int j=0;j<len;j++)
        {
            if(a[i][j]!='?') continue;
            for(int k=(j==0?1:0);k<=9;k++)
                if(p[i]-(9-k)*pw[len-j-1]>p[i-1])
                    {p[i]-=(9-k)*pw[len-j-1];break;}
        }
    }
    if(!ok) puts("NO");
    else
    {
        puts("YES");
        for(int i=1;i<=n;i++) printf("%d\n",p[i]);
    }
    return 0;
}