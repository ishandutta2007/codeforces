#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100100],chk[1001001],sz,chk2[1001001],ans=1,l,out[100100];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);

    for(int i=1;i<=n;i++){
        if(a[i] > 0){
            if(chk[a[i]] || chk2[a[i]] == ans) return !printf("-1");
            chk[a[i]] = 1;
            chk2[a[i]] = ans;
            sz++;
        }else{
            a[i] = -a[i];
            if(!chk[a[i]]) return !printf("-1");
            chk[a[i]] = 0;
            sz--;
            if(sz == 0){
                out[ans] = i - l;
                ans++;
                l = i;
            }
        }
    }
    if(sz) return !printf("-1");

    printf("%d\n",ans-1);
    for(int i=1;i<ans;i++) printf("%d ",out[i]);
}