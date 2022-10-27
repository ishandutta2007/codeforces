#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a,b,ma;
int s[maxn];

int main(){
    scanf("%d%d%d",&n,&b,&a);
    for(int i=1;i<=n;i++){
        scanf("%d",&s[i]);
    }
    ma=a;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(s[i]==0){
            if(a){
                a--;
                ans=max(ans,i);
                continue;
            }
            else{
                if(b)b--;
                else
                    return printf("%d\n",ans),0;
                ans=max(ans,i);
                continue;
            }
        }
        else{
            if(a==ma){
                a--;
                ans=max(ans,i);
                continue;
            }
            if(b){
                b--;
                a=min(a+1,ma);
                ans=max(ans,i);
            }
            else{
                if(a)
                a--;
                else
                    return printf("%d\n",ans),0;
                ans=max(ans,i);
                continue;
            }
        }
    }
    printf("%d\n",ans);

}