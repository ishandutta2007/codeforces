#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int a[maxn],n,q,suf[maxn];
pair<int,int> last[maxn];
int mi[maxn];

int main(){
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        int t,p,x;
        scanf("%d",&t);
        if(t==1){
            scanf("%d%d",&p,&x);
            last[p]=make_pair(i,x);
        }
        else{
            scanf("%d",&x);
            mi[i]=x;
        }
    }
    for(int i=q;i>=0;i--){
        suf[i]=max(suf[i+1],mi[i]);
    }
    for(int i=1;i<=n;i++){
        if(last[i].first==0){
            printf("%d ",max(a[i],suf[0]));
        }
        else{
            a[i]=last[i].second;
            printf("%d ",max(a[i],suf[last[i].first+1]));
        }
    }
}
/*
    Good Luck
        -Lysithea
*/