#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,chk[200200];
int main(){
    scanf("%d",&t);
    while(t--){
        int ans = 1e9;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int a; scanf("%d",&a);
            if(chk[a]) ans = min(ans, i - chk[a] + 1);
            chk[a] = i;
        }
        printf("%d\n",ans > n ? -1 : ans);
        for(int i=1;i<=n;i++) chk[i] = 0;
    }
}