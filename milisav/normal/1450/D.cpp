#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int t;
int n;
int a[maxn];
int pl[maxn];
int nl[maxn];
char s[maxn];
bool ap[maxn];
int ltst[maxn];
vector<int> pos[maxn];
int pe[maxn];
int gp[maxn];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        s[0]='1';
        for(int i=0;i<n;i++) {
            scanf("%d",&a[i]);
            if(ap[a[i]]) s[0]='0';
            ap[a[i]]=true;
            pos[a[i]].push_back(i);
        }
        if(ap[1]) {
            s[n-1]='1';
        }
        else {
            s[n-1]='0';
        }
        for(int i=1;i<=n;i++) {
            ap[i]=false;
            ltst[i]=-2;
        }
        pl[0]=-1;
        ltst[a[0]]=0;
        for(int i=1;i<n;i++) {
            pl[i]=i-1;
            pe[i]=ltst[a[i]];
            while(pl[i]>=0 && a[pl[i]]>=a[i]) pl[i]=pl[pl[i]];
            ltst[a[i]]=i;
        }
        nl[n-1]=n;
        for(int i=n-2;i>=0;i--) {
            nl[i]=i+1;
            while(nl[i]<n && a[nl[i]]>=a[i]) nl[i]=nl[nl[i]];
        }
        for(int val=1;val<=n;val++) {
            gp[val]=n-val;
            int mx=0;
            for(auto i:pos[val]) mx=max(mx,nl[i]-pl[i]-2);
            gp[val]=min(gp[val],mx);
        }
        int cmin=gp[1];
        for(int i=2;i<n;i++) {
            cmin=min(cmin,gp[i]);
            if(n-i<=cmin) s[n-i]='1';
            else s[n-i]='0';
        }
        printf("%s\n",s);
        for(int i=0;i<n;i++) {
            s[i]=0;
            pos[a[i]].clear();
        }
    }
    return 0;
}