#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int dp[105][70000];
///the maximum number of projects he can complete
///from 1 ... x and have rating y
struct pa{
    int a,b;
    void read(){
        scanf("%d%d",&a,&b);
    }
    bool operator<(const pa &x)const{
        return a+b>x.a+x.b;
    }
}p;
int n,r;
pair<int,int> b[105];
void upd(int &x,int y){
    if(x<y)x=y;
}
vector<pa> pos;
vector<pa> neg;

int main(){
    scanf("%d%d",&n,&r);
    for(int i=1;i<=n;i++){
        p.read();
        if(p.b>=0){
            pos.push_back(p);
        }
        else
            neg.push_back(p);
    }
    int ans=0;
    while(true){
        bool any=false;
        for(int i=0;i<(int)pos.size();i++){
            if(r>=pos[i].a){
                r+=pos[i].b;
                any=true;
                swap(pos[i],pos.back());
                pos.pop_back();
                ans++;
            }
        }
        if(!any)break;
    }
    sort(neg.begin(),neg.end());
    int m=(int)neg.size();
    for(int i=0;i<=m;i++){
        for(int j=0;j<=60000;j++)
            dp[i][j]=-maxn;
    }
    dp[0][r]=ans;
    for(int i=0;i<m;i++){
        for(int j=0;j<=60000;j++){
            upd(dp[i+1][j],dp[i][j]);
            if(j>=neg[i].a&&j+neg[i].b>=0){
                upd(dp[i+1][j+neg[i].b],dp[i][j]+1);
            }
        }
    }
    for(int i=0;i<=60000;i++){
        upd(ans,dp[m][i]);
    }
    printf(ans==n?"YES\n":"NO\n");
}