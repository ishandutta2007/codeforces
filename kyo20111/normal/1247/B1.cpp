#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,k,d,a[200200],chk[1001001];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&n,&k,&d);
        for(int i=1;i<=n;i++) scanf("%d",a+i);

        int cnt = 0, ans = 1e9;
        for(int i=1;i<d;i++) if(chk[a[i]]++ == 0) cnt++;

        for(int i=d;i<=n;i++){
            if(chk[a[i]]++ == 0) cnt++;
            ans = min(ans, cnt);
            if(--chk[a[i-d+1]] == 0) cnt--;
        }
        for(int i=n-d+2;i<=n;i++) --chk[a[i]];
        printf("%d\n",ans);
    }
}