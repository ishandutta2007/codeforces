#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5;
int n,q,a[maxn],dp[maxn],l[maxn],r[maxn],qs[maxn],paint,ans;

int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=q;i++)
        scanf("%d%d",&l[i],&r[i]);
    for(int i=1;i<=q;i++){
            paint=0;
        for(int j=1;j<=n;j++){
            a[j]=0;
        }
        dp[0]=0,qs[0]=0;
        for(int j=1;j<=q;j++){
            if(j!=i){
                a[l[j]]++;
                a[r[j]+1]--;
            }
        }
        for(int j=1;j<=n;j++){
            dp[j]=dp[j-1];
            dp[j]+=a[j];
            if(dp[j])
                paint++;
            qs[j]=qs[j-1]+(dp[j]==1);
        }
        for(int j=1;j<=q;j++){
            if(j!=i){
                ans=max(ans,paint-(qs[r[j]]-qs[l[j]-1]));
            }
        }
    }
    printf("%d\n",ans);

}


/*#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+2;
int n,q,c,p,dp[maxn][maxn],dp1[maxn],l[maxn],r[maxn];
vector<int> a[maxn];

int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=q;i++){
        scanf("%d%d",&l[i],&r[i]);
        for(int j=l[i];j<=r[i];j++){
            if(a[j].size()<3)
            a[j].push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i].size()){
            p++;
        }
        if(a[i].size()==1){
            dp1[a[i][0]]++;
        }
        if(a[i].size()==2){
            if(a[i][0]>a[i][1]) swap(a[i][0],a[i][1]);
            dp[a[i][0]][a[i][1]]++;
        }
    }
    int best=1e9;
    for(int i=1;i<=q;i++){
        for(int j=i+1;j<=q;j++){
            best=min(best,dp1[i]+dp1[j]+dp[i][j]);
        }
    }
    printf("%d\n",p-best);
}
*/