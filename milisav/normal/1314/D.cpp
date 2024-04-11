#include<bits/stdc++.h>
using namespace std;
int d[500][500];
vector<pair<int,int>> dst[500][500];
int ans=1e9;
int n,k;
vector<int> chs;
int cur() {
    int ca=0;
    for(int i=1;i<chs.size();i++) {
        int u=chs[i-1];
        int v=chs[i];
        for(auto t:dst[u][v]) {
            bool pos=true;
            for(auto j:chs) {
                if(t.second==j) {
                    pos=false;
                    break;
                }
            }
            if(pos) {
                ca+=t.first;
                break;
            }
        }
    }
    return ca;
}
void choose(int t) {
    if(t==0) {
        chs.push_back(1);
        ans=min(ans,cur());
        chs.pop_back();
        return;
    }
    for(int i=1;i<=n;i++) {
        chs.push_back(i);
        choose(t-1);
        chs.pop_back();
    }
}
int main() {
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) scanf("%d",&d[i][j]);
    }
    int t=k/2-1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            for(int k=1;k<=n;k++) {
                if(k!=i && k!=j) dst[i][j].push_back({d[i][k]+d[k][j],k});
            }
            sort(dst[i][j].begin(),dst[i][j].end());
        }
    }
    if(t==0) {
        printf("%d",dst[1][1][0]);
        return 0;
    }
    chs.push_back(1);
    choose(t);
    printf("%d",ans);
    return 0;
}