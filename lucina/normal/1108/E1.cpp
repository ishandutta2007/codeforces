#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m,a[maxn],mn[maxn][2],s[maxn],u,v,w,mini;
struct pa{
    int l;
    int r;
    int pos;
}b[maxn];
bool sort1(pa x,pa y){
    return x.l<y.l;
}
bool sort2(pa x,pa y){
    return x.r<y.r;
}
int main(){
    scanf("%d%d",&n,&m);
    int mi=1e9;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=a[i];
        mi=min(mi,s[i]);
        }
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        b[i]={u,v,i};
        }
    sort(b+1,b+1+m,sort1);
    for(int i=1;i<=3e5+5;i++){
        mn[i][0]=mi;mn[i][1]=mi;
    }
    int pt=n;
    mini=mi;
    for(int i=m;i>=1;i--){
        for(int j=b[i].l;j<=b[i].r;j++){
            a[j]--;
        }
        for(int j=n;j>=b[i].l;j--){
            mini=min(mini,a[j]);
        }
        for(int j=1;j<b[i].l;j++){
            mn[j][0]=min(mn[j][0],mini);
        }
    }
    for(int i=1;i<=n;i++)
        a[i]=s[i];
    sort(b+1,b+1+m,sort2);
    mini=1e9;
    pt=1;
    for(int i=1;i<=m;i++){
        for(int j=b[i].l;j<=b[i].r;j++){
            a[j]--;
        }
        for(int j=1;j<=b[i].r;j++){
            mini=min(mini,a[j]);
        }
        for(int j=b[i].r+1;j<=n;j++){
            mn[j][1]=min(mn[j][1],mini);
        }
    }
    int ans=0,d=0;
    for(int i=1;i<=n;i++){
            if(s[i]-mn[i][0]>ans||s[i]-mn[i][1]>ans){
                d=i;
                ans=s[i]-min(mn[i][0],mn[i][1]);
            }
    }
    queue<int> x;
    for(int i=1;b[i].r<d&&i<=m;i++){
        x.push(b[i].pos);
    }
    sort(b+1,b+1+m,sort1);
    for(int i=m;b[i].l>d&&i>=1;i--){
        x.push(b[i].pos);
    }
    printf("%d\n",ans);
    printf("%d\n",x.size());
    while(!x.empty()){
        printf("%d ",x.front());
        x.pop();
    }
}