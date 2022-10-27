#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m,t,x,y,d,ans,ans1;

int main(){
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        ans=1e9+5,ans1=1e9+5;
        scanf("%d%d%d%d",&n,&x,&y,&d);
        if((x-y)%d&&(n-y)%d&&(y-1)%d){
            printf("%d\n",-1);
            continue;
            }
        if((x-y)%d==0){
            printf("%d\n",abs(x-y)/d);
            continue;
            }
        if((y-1)%d==0){
        ans=(x-1)/d;
        if((x-d*ans)>1)
            ans++;
        ans+=((y-1)/d);
        }
        if((n-y)%d==0){
        ans1=(n-x)/d;
        if((x+d*(ans1))<n)
            ans1++;
        ans1+=((n-y)/d);
        }
        printf("%d\n",min(ans,ans1));

            }

    }