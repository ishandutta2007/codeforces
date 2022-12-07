
/*****************************************
Author: lizi
Email: lzy960601@outlook.com
****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
  
int a[1005];
int n,m;
bool f[1005],s[1005];

int main()
{
    scanf("%d%d",&n,&m);
    if(n>m)
    {
        printf("YES");
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        a[i]=x%m;
    }
    memset(f,false,sizeof(f));
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)s[j]=f[j],f[j]=false;
        f[a[i]]=true;
        for(int j=0;j<m;j++)f[(j+a[i])%m]=s[(j+a[i])%m] | s[j] | f[(j+a[i])%m];
    }
    if(f[0])printf("YES");else printf("NO");
    return 0;
}