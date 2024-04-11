#include<bits/stdc++.h>
#define maxn 400000
using namespace std;
typedef long long lld;
lld mod=998244353;
lld step(lld a,lld b) {
    if(b==0ll) return 1;
    if(b&1ll) return (a*step(a,b-1ll))%mod;
    else return step((a*a)%mod,b>>1ll);
}
lld inverse(lld a) {
    return step(a,mod-2);
}
int n;
int x[maxn];
int v[maxn];
int p[maxn];
struct col {
    lld tp,tq;
    int i;
    int di;
    int j;
    int dj;
};
bool operator <(col g,col h) {
    return g.tp*h.tq<h.tp*g.tq;
}
vector<col> a;
lld seg[5*maxn][4];
lld pr[maxn][4];
bool ban[maxn][4];
void setseg(int id,int l,int r) {
    if(l==r) {
        seg[id][0]=((100-p[l])*inverse(100))%mod;
        seg[id][3]=(p[l]*inverse(100))%mod;
        /*seg[id][0]=1;
        seg[id][3]=1;*/
        return;
    }
    int m=(l+r)>>1;
    setseg(id*2+1,l,m);
    setseg(id*2+2,m+1,r);
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            seg[id][2*i+j]=0;
            for(int g=0;g<2;g++) {
                for(int h=0;h<2;h++) {
                    if(!ban[m][2*g+h]) {
                        seg[id][2*i+j]=(seg[id][2*i+j]+((seg[id*2+1][i*2+g]*seg[id*2+2][h*2+j])%mod));
                    }
                }
            }
            seg[id][2*i+j]%=mod;
        }
    }
}
void update(int id,int l,int r,int x) {
    if(x>r) return;
    if(x<l) return;
    int m=(l+r)>>1;
    if(x==m) {
        for(int i=0;i<2;i++) {
            for(int j=0;j<2;j++) {
                seg[id][2*i+j]=0;
                for(int g=0;g<2;g++) {
                    for(int h=0;h<2;h++) {
                        if(!ban[m][2*g+h]) {
                            seg[id][2*i+j]=(seg[id][2*i+j]+((seg[id*2+1][i*2+g]*seg[id*2+2][h*2+j])%mod));
                        }
                    }
                }
                seg[id][2*i+j]%=mod;
            }
        }
        return;
    }
    else {
        update(id*2+1,l,m,x);
        update(id*2+2,m+1,r,x);
        for(int i=0;i<2;i++) {
            for(int j=0;j<2;j++) {
                seg[id][2*i+j]=0;
                for(int g=0;g<2;g++) {
                    for(int h=0;h<2;h++) {
                        if(!ban[m][2*g+h]) {
                            seg[id][2*i+j]=(seg[id][2*i+j]+((seg[id*2+1][i*2+g]*seg[id*2+2][h*2+j])%mod));
                        }
                    }
                }
                seg[id][2*i+j]%=mod;
            }
        }
    }
}
/*pair<pair<lld,lld>,pair<lld,lld> > query(int id,int l,int r,int x,int mask) {
    if(l==r) return 0;
    int m=(l+r)>>1;
    if(x==m) {
        int g=mask>>1;
        int h=mask&1;
        return {{pr[x][mask]*(seg[id*2+1][g]*seg[id*2+2][h*2]%mod),pr[x][mask]},{}};
        for(int i=0;i<2;i++) {
            for(int j=0;j<2;j++) {

            }
        }
    }
    else {
        if(x<m) {

        }
    }
}*/
lld tot() {
    return (seg[0][0]+seg[0][1]+seg[0][2]+seg[0][3])%mod;
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d %d %d",&x[i],&v[i],&p[i]);
    }
    lld invs=inverse(100);
    lld invss=(invs*invs)%mod;
    for(int i=0;i<n-1;i++) {
        pr[i][3]=((p[i]*p[i+1])*invss)%mod;
        pr[i][2]=((p[i]*(100-p[i+1]))*invss)%mod;
        pr[i][1]=(((100-p[i])*p[i+1])*invss)%mod;
        pr[i][0]=(((100-p[i])*(100-p[i+1]))*invss)%mod;
        a.push_back({x[i+1]-x[i],v[i+1]+v[i],i,1,i+1,0});
        if(v[i]>v[i+1]) a.push_back({x[i+1]-x[i],v[i]-v[i+1],i,1,i+1,1});
        if(v[i+1]>v[i]) a.push_back({x[i+1]-x[i],v[i+1]-v[i],i,0,i+1,0});
    }
    setseg(0,0,n-1);
    sort(a.begin(),a.end());
    lld ans=0;
    for(auto t:a) {
        lld p1=tot();
        pr[t.i][t.di*2+t.dj]=0;
        ban[t.i][t.di*2+t.dj]=true;
        update(0,0,n-1,t.i);
        lld p2=tot();
        lld pro=(p1-p2);
        if(pro<0) pro+=mod;
        ans=(ans+pro*(t.tp*inverse(t.tq)%mod))%mod;
    }
    printf("%lld",ans);
    return 0;
}