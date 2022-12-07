/*****************************************
Author: lizi
Email: lzy960601@outlook.com
*****************************************/
  
#include<bits/stdc++.h>
#include<ctime>

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
 
struct node
{int value,nex;}a[50005];
int n,st,x;

node query(int t)
{
    printf("? %d\n",t);
    fflush(stdout);
    int va,ne;
    scanf("%d%d",&va,&ne);
    return {va,ne};
}

int rnd()
{
    return rand()*1234+rand();
}

int main()
{
    srand(time(NULL));
    scanf("%d%d%d",&n,&st,&x);
    a[st]=query(st);
    if(a[st].value>=x)
    {
        printf("! %d\n",a[st].value);
        fflush(stdout);
        return 0;
    }
    for(int i=1;i<=min(n-1,1000);i++)
    {
        int t=rnd()%n+1;
        while(a[t].nex!=0)t=rnd()%n+1;
        a[t]=query(t);
    }
    int u=st;
    int now=1e9+7;
    for(int i=1;i<=n;i++)
    {
        if(a[i].value>=x)now=min(a[i].value,now);
        if(a[i].nex==0 || a[i].value>x)continue;
        if(a[i].value>a[u].value)u=i;
    }
    if(a[u].value==x)
    {
        printf("! %d\n",a[u].value);
        fflush(stdout);
        return 0;
    }
    int cnt=950,p=u;
    while(cnt--)
    {
        u=a[p].nex;
        if(u<0)
        {
            printf("! -1\n");
            fflush(stdout);
            return 0;
        }
        a[u]=query(u);
        if(a[u].value>=x)
        {
            printf("! %d\n",a[u].value);
            fflush(stdout);
            return 0;
        }
        p=u;
    }
    printf("! %d\n",now);
    fflush(stdout);
    return 0;
}