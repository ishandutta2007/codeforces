#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m,s,r,ans,fuck[maxn],l;
vector <int>a[maxn],b[maxn];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&s,&r);
        a[s].push_back(r);
    }
    int sum=0,d=0;
    for(int i=1;i<=m;i++){
        sort(a[i].begin(),a[i].end());
        sum=0;
        l=a[i].size();
        for(int j=l-1;j>=0;j--){
            sum+=a[i][j];
            if(sum<0)
                break;
            fuck[l-j]+=sum;
        }
    }
    ans=-1e9;
    for(int i=1;i<=n;i++){
        ans=max(ans,fuck[i]);
    }
    if(ans>0)
    printf("%d\n",ans);
    else
    printf("%d\n",0);
}