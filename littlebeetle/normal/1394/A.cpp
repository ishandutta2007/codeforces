#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1000020;
int n,n1,n2,d,m,a[N],b[N],x;
ll sa[N],sb[N],Ans,i,j;
bool cmp(int x,int y){
    return x>y;
}
void Upd(ll i){
    if(i==0)
        j=n1;
    else
        j=n1-((i-1)*d-(n2-i));
    if(j>n1)j=n1;
    if(j<0)return;
    Ans=max(Ans,sa[j]+sb[i]);
}
int main(){
    scanf("%d%d%d",&n,&d,&m);
    while(n--){
        scanf("%d",&x);
        if(x<=m)
            a[++n1]=x;
        else
            b[++n2]=x;
    }   
    sort(a+1,a+n1+1,cmp);
    sort(b+1,b+n2+1,cmp);
    for(i=1;i<=n1+n2;i++){
        sa[i]=a[i]+sa[i-1];
        sb[i]=b[i]+sb[i-1];
    }
    for(i=0;i<=n2;i++)
        Upd(i);
    printf("%lld",Ans);
    
}