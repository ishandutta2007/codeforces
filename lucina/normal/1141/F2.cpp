#include<bits/stdc++.h>
using namespace std;
const int maxn=1505;
int a[maxn],s[maxn],n,ma;
struct pa{
int l;
int r;
}ans1[maxn],ans2[maxn];
unordered_map<int,vector<pa>> f;
vector<pa> g;

int main(){
    f.reserve(1510*1510);
    f.max_load_factor(0.25);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=s[i-1]+a[i];
    }
    for(int j=1;j<=n;j++)
        for(int i=1;i<=j;i++)
            f[s[j]-s[i-1]].push_back({i,j});
    int pt=0,r1=0;
    for(pair<int,vector<pa>> i:f){
        g=i.second;
         r1=0;
        pt=0;
        for(int j=0;j<g.size();j++){
            if(g[j].l>r1){
                pt++;
                ans2[pt].l=g[j].l;
                ans2[pt].r=g[j].r;
                r1=g[j].r;
            }
        }
        if(pt>ma){
         ma=pt;
         for(int j=1;j<=pt;j++){
            ans1[j]=ans2[j];
         }
        }
        }
    printf("%d\n",ma);
    for(int i=1;i<=ma;i++){
        printf("%d %d\n",ans1[i].l,ans1[i].r);
    }
}