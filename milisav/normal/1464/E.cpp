#include<bits/stdc++.h>
#define maxl 1050
#define maxn 200000
using namespace std;
long long mod=998244353;
long long step(long long a,long long b) {
    if(b==0ll) return 1ll;
    if(b&1ll) return (a*step(a,b-1ll))%mod;
    else return step((a*a)%mod,b>>1ll);
}
long long inverse(long long a) {
    return step(a,mod-2);
}
int n,m;
vector<int> a[maxn];
vector<int> b[maxn];
vector<int> toposa;
int cnt[maxn];
int mex[maxn];
bool fnasd[maxn];
int mv;
long long pr[maxl][maxl];
long long c[maxn];
int main() {
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        a[u].push_back(v);
        b[v].push_back(u);
        cnt[u]++;
    }
    for(int i=1;i<=n;i++) {
        if(cnt[i]==0) toposa.push_back(i);
    }
    for(int iter=0;iter<toposa.size();iter++) {
        int u=toposa[iter];
        for(auto v:b[u]) {
            cnt[v]--;
            if(cnt[v]==0) {
                toposa.push_back(v);
            }
        }
        for(auto v:a[u]) {
            fnasd[mex[v]]=true;
        }
        while(fnasd[mex[u]]) mex[u]++;
        for(auto v:a[u]) {
            fnasd[mex[v]]=false;
        }
    }
    for(int i=1;i<=n;i++) {
        cnt[i]=0;
    }
    mv=0;
    for(int i=1;i<=n;i++) {
        cnt[mex[i]]++;
        mv=max(mv,mex[i]);
    }
    m=0;
    while((1<<m)<=mv) m++;
    m=(1<<m);
    /*for(int i=0;i<m;i++) {
        cout<<cnt[i]<<" "<<endl;
    }*/
    long long ni=inverse(n+1);
    c[0]=ni;
    for(int i=0;i<m;i++) {
        for(int j=0;j<m;j++) {
            if(j!=i) {
                pr[i][j]=(-cnt[i^j]*ni)%mod;
            }
            else {
                pr[i][i]=(1-cnt[0]*ni)%mod;
            }
            if(pr[i][j]<0) pr[i][j]+=mod;
        }
    }
    for(int i=0;i<m;i++) {
        int sel=i;
        while(sel<m && pr[sel][i]==0) sel++;
        if(sel==m) continue;
        for(int j=0;j<m;j++) {
            swap(pr[i][j],pr[sel][j]);
        }
        swap(c[i],c[sel]);
        long long inv1=inverse(pr[i][i]);
        for(int j=i+1;j<m;j++) {
            long long dif=(pr[j][i]*inv1)%mod;
            c[j]=(c[j]-c[i]*dif)%mod;
            for(int k=i;k<m;k++) {
                pr[j][k]=(pr[j][k]-pr[i][k]*dif)%mod;
            }
        }
    }
    for(int i=m-1;i>=0;i--) {
        if(pr[i][i]==0) continue;
        long long inv1=inverse(pr[i][i]);
        for(int j=i-1;j>=0;j--) {
            long long dif=(pr[j][i]*inv1)%mod;
            c[j]=(c[j]-c[i]*dif)%mod;
            pr[j][i]=0;
            /*for(int k=i;k<m;k++) {
                pr[j][k]=(pr[j][k]-pr[i][k]*dif)%mod;
            }*/
        }
    }
    long long alice=(1-c[0]*inverse(pr[0][0]))%mod;
    if(alice<0) alice+=mod;
    printf("%lld",alice);
    return 0;
}