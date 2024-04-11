#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
typedef long long ll;
typedef double db;
void gn(int &x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')sg=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sg;
}
void gn(ll &x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')sg=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sg;
}
const int mo=1000000007;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}


struct pkt{
    int x,y;
    int type;
    pkt operator-(const pkt&b){
        return (pkt){x-b.x,y-b.y};
    }
    ll operator*(const pkt&b){
        return 1ll*x*b.y-1ll*y*b.x;
    }
}p[211111],ini;

int n,m;

int cmp(const pkt&a,const pkt&b){
    if(a.x==b.x && a.y==b.y){
        return a.type<b.type;
    }
    if(a.x==b.x)return a.y>b.y;
    return a.x<b.x;
}
pkt arr[211111];int top=0;
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%d%d",&ini.x,&ini.y);
    for (int i=1;i<=n;i++)scanf("%d%d",&p[i].x,&p[i].y),p[i].type=0;
    for (int i=n+1;i<=m+n;i++)scanf("%d%d",&p[i].x,&p[i].y),p[i].type=1;
    sort(p+1,p+1+m+n,cmp);
    for (int i=1;i<=m+n;i++){
        if(i>1 && p[i].x==p[i-1].x && p[i].y==p[i-1].y)continue;
        while(top && p[i].y>arr[top].y)top--;
        while(top>=2 && (arr[top]-arr[top-1])*(p[i]-arr[top])>0)top--;
        arr[++top]=p[i];
    }
    for (int i=1;i<=top;i++)if(arr[i].type==0){
        printf("Max\n");
        return 0;
    }
    printf("Min\n");
    return 0;
}