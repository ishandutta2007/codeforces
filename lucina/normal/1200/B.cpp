#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int T,n,k,m,pre,h,useless;
void solve(){
    scanf("%d%d%d",&n,&m,&k);
    scanf("%d",&pre);
    int cur=m,res=n-1;
    for(int i=1;i<n;i++){
        scanf("%d",&h);
        --res;
        int low=max(0,h-k);
        if(pre>=low){
            cur+=(pre-low);
        }
        else{
            if(cur<low-pre){
                printf("NO\n");
                while(res--)scanf("%d",&useless);
                return;
            }
            cur-=(low-pre);
        }
        pre=h;
    }
    printf("YES\n");
    return;
}
 
int main(){
    scanf("%d",&T);
    while(T--){
        solve();
    }
}