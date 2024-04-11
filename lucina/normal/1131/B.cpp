#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=3e5+10;
int a,b,p,q,n,ans,x;

int main(){
    scanf("%d",&n);
    q=-1;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a,&b);
        ans+=max(0,min(a,b)-max(p,q)+(p!=q));
        p=a,q=b;
    }
    printf("%d\n",ans);

}