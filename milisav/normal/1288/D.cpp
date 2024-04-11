#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int n,m;
int a[maxn][10];
vector<int> msk[1024];
bool pos(int t) {
    for(int i=0;i<(1<<m);i++) msk[i].clear();
    for(int i=0;i<n;i++) {
        int cm=0;
        for(int j=0;j<m;j++) {
            if(a[i][j]>=t) cm|=(1<<j);
        }
        msk[cm].push_back(i);
    }
    for(int i=0;i<(1<<m);i++) {
        for(int j=i;j<(1<<m);j++) {
            if((i|j) == (1<<m)-1 && msk[i].size()>0 && msk[j].size()>0) return true;
        }
    }
    return false;
}
int main() {
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) scanf("%d",&a[i][j]);
    }
    int l=0;
    int r=1e9;
    while(l<r) {
        int t=(l+r+1)>>1;
        if(pos(t)) l=t;
        else r=t-1;
    }
    pos(l);
    for(int i=0;i<(1<<m);i++) {
        for(int j=i;j<(1<<m);j++) {
            if((i|j) == (1<<m)-1 && msk[i].size()>0 && msk[j].size()>0) {
                printf("%d %d",msk[i][0]+1,msk[j][0]+1);
                return 0;
            }
        }
    }
    return 0;
}