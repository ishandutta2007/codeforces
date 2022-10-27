#include<stdio.h>
#include<algorithm>
using namespace std;

int n,x,y,ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x,&y);
        ans=max(ans,x+y);
    }
    printf("%d\n",ans);
}