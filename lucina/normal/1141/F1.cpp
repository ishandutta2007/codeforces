#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int a[maxn],s[maxn],n,ma;
struct pa{
int l;
int r;
bool operator<(const pa x)const{
    return r<x.r;
}
}ans1[maxn],ans2[maxn];
map<int,vector<pa>> f;
map<int,bool> ch;
vector<int> q;

int main(){
    ma=-1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            f[s[j]-s[i]+a[i]].push_back({i,j});
            if(!ch[s[j]-s[i]+a[i]]){
                ch[s[j]-s[i]+a[i]]=true;
                q.push_back(s[j]-s[i]+a[i]);
            }
        }
    }
    int pt=0,r1=0;
    for(auto i:q){
        sort(f[i].begin(),f[i].end());
         r1=0;
        pt=0;
        for(int j=0;j<f[i].size();j++){
            if(f[i][j].l>r1){
                pt++;
                ans2[pt].l=f[i][j].l;
                ans2[pt].r=f[i][j].r;
                r1=max(r1,f[i][j].r);
            }
        }
        if(pt>ma){
         ma=pt;
         for(int j=1;j<=pt;j++){
            ans1[j].l=ans2[j].l,
            ans1[j].r=ans2[j].r;
         }
        }
        }
    printf("%d\n",ma);
    for(auto i=1;i<=ma;i++){
        printf("%d %d\n",ans1[i].l,ans1[i].r);
    }
}