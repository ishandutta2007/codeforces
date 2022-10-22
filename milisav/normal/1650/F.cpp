#include<bits/stdc++.h>
#define maxn 100100
using namespace std;
int t;
int n,m;
int a[maxn];
vector<pair<int,pair<int,int>>> opt[maxn];
vector<int> ord;
int dp[maxn][201];
int pj[maxn][201];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            opt[i].clear();
        }
        for(int i=1;i<=m;i++) {
            int e,t,p;
            scanf("%d %d %d",&e,&t,&p);
            opt[e].push_back({i,{t,p}});
        }
        bool ok=true;
        int ct=0;
        for(int i=1;i<=n;i++) {
            int j=1;
            for(int p=1;p<=200;p++) dp[0][p]=1e9+1;
            for(auto option:opt[i]) {
                for(int p=1;p<=200;p++) {
                    dp[j][p]=dp[j-1][p];
                    pj[j][p]=pj[j-1][p];
                }
                int ind=option.first;
                int tm=option.second.first;
                int pr=option.second.second;
                for(int p=200;p>=pr;p--) {
                    if(dp[j][p]>dp[j-1][p-pr]+tm) {
                        dp[j][p]=dp[j-1][p-pr]+tm;
                        pj[j][p]=j;
                    }
                }
                j++;
            }
            j--;
            int p=100;
            for(int pos=101;pos<=200;pos++) {
                if(dp[j][pos]<dp[j][p]) p=pos;
            }
            //cout<<j<<" "<<p<<endl;
            ct+=dp[j][p];
            //cout<<dp[j][p]<<" ";
            if(ct>a[i]) {
                ok=false;
                break;
            }
            j=pj[j][p];
            //cout<<dp[j][p]<<endl;
            while(p!=0) {
                //cout<<j<<endl;
                int cj=j-1;
                int ind=opt[i][cj].first;
                int pr=opt[i][cj].second.second;
                ord.push_back(ind); 
                p-=pr;
                j=pj[j-1][p]; 
            }
        }
        if(ok) {
            printf("%d\n",ord.size());
            for(int i=0;i<ord.size();i++) printf("%d ",ord[i]);
            printf("\n");
        }
        else printf("-1\n");
        ord.clear();
    }
    return 0;
}