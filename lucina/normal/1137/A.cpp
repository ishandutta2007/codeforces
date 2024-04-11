#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,m,b[maxn][maxn],s[maxn][maxn],t[maxn][maxn],mx1[maxn],mx2[maxn];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&b[i][j]);
        }
    }
    vector<pair<int,int>> f;
    int pt=1,u=0;
    for(int i=1;i<=n;i++){
        f.clear();
        for(int j=1;j<=m;j++)
        f.push_back({b[i][j],j});
        sort(f.begin(),f.end());
        pt=0,u=0;
        for(int j=0;j<m;j++){
            pt=j;
            while(f[pt+1].first==f[j].first&&pt<m-1)
                pt++;
            u++;
            for(int k=j;k<=pt;k++){
                s[i][f[k].second]=u;
            }
            j=pt;
        }
    }
    for(int j=1;j<=m;j++){
            f.clear();
        for(int i=1;i<=n;i++)
        f.push_back({b[i][j],i});
        sort(f.begin(),f.end());
        pt=0,u=0;
        for(int i=0;i<n;i++){
            pt=i;
            while(f[pt+1].first==f[i].first&&pt<n-1)
                pt++;
            u++;
            for(int k=i;k<=pt;k++){
                t[f[k].second][j]=u;
            }
            i=pt;
        }
    }
    int ans;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            mx1[i]=max(mx1[i],s[i][j]);
    for(int j=1;j<=m;j++)
        for(int i=1;i<=n;i++)
        mx2[j]=max(mx2[j],t[i][j]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            u=max(s[i][j],t[i][j]);
            ans=max(u+mx1[i]-s[i][j],u+mx2[j]-t[i][j]);
            printf("%d ",ans);
        }
        printf("\n");
    }

}