#include<bits/stdc++.h>
#define maxn 300000
typedef long long lld;
using namespace std;
lld mod[2];
lld has[maxn][2];
lld deg[maxn][2];
lld invdeg[maxn][2];
lld b[2];
lld step(lld a,lld b,int i) {
    if(b==0ll) return 1ll;
    if(b&1ll) return (a*step(a,b-1ll,i))%mod[i];
    else return step((a*a)%mod[i],b>>1ll,i);
}
lld inverse(lld a,int i) {
    return step(a,mod[i]-2,i);
}
int n;
char s[maxn];
int c[maxn];
vector<int> t;
int nv[maxn];
int pv[maxn];
int nz[maxn];
int pz[maxn];
int rv[maxn];
int pos[maxn];
int h=0;
void calc_has() {
    for(int w=0;w<2;w++) {
        deg[0][w]=1;
        for(int i=1;i<maxn;i++) {
            deg[i][w]=(b[w]*deg[i-1][w])%mod[w];
        }
        for(int i=0;i<maxn;i++) {
            invdeg[i][w]=inverse(deg[i][w],w);
        }
        has[0][w]=0;
        for(int i=1;i<=h+1;i++) {
            has[i][w]=(has[i-1][w]+deg[i][w]*t[i-1])%mod[w];
        }
    }
}
pair<lld,lld> fnd_has(int i,int j) {
    pair<lld,lld> rt;
    for(int w=0;w<2;w++) {
        lld vl=((has[j+1][w]-has[i+1][w])*invdeg[i+1][w])%mod[w];
        vl+=mod[w];
        vl%=mod[w];
        if(w==0) rt.first=vl;
        else rt.second=vl;
    }
    return rt;
}
int main() {
    mod[0]=1e9+7;
    mod[1]=998244353;
    b[0]=1e7+7;
    b[1]=1e8+7;
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++) {
        c[i]=c[i-1];
        if(s[i]=='0') c[i]++;
    }
    c[n+1]=c[n];
    nz[n+1]=n+1;
    for(int i=n;i>=0;i--) {
        nz[i]=nz[i+1];
        if(s[i]=='0') nz[i]=i;
    }
    nz[0]=nz[1];
    for(int i=0;i<=n+1;i++) rv[i]=-1;
    pz[0]=0;
    for(int i=1;i<=n;i++) {
        pz[i]=pz[i-1];
        if(s[i]=='0') pz[i]=i;
    }
    pz[n+1]=pz[n];
    int lb=0;
    h=0;
    for(int i=1;i<=n;i++) {
        nv[i]=0;
        if(s[i]=='1') {
            lb++;
        }
        else {
            if(lb%2==1) {
                rv[i-1]=h;
                pos[h]=i-1;
                h++;
            }
            lb=0;
        }
    }
    if(lb%2==1) {
        rv[n]=h;
        pos[h]=n;
        h++;
    }
    if(h>0) {
        t.push_back(c[pos[0]]);
        for(int i=1;i<h;i++) {
            t.push_back(c[pos[i]]-c[pos[i-1]]);
        }
        t.push_back(c[n]-c[pos[h-1]]);
        calc_has();
    }
    nv[n+1]=n+1;
    for(int i=n;i>=0;i--) {
        nv[i]=nv[i+1];
        if(rv[i]!=-1) nv[i]=i;
    }
    pv[0]=0;
    for(int i=1;i<=n+1;i++) {
        pv[i]=pv[i-1];
        if(rv[i]!=-1) pv[i]=i;
    }
    int q;
    scanf("%d",&q);
    int l1,l2,l;
    while(q--) {
        scanf("%d %d %d",&l1,&l2,&l);
        if(l<=2) {
            bool pos=true;
            for(int i=0;i<l && pos;i++) {
                if(s[l1+i]!=s[l2+i]) pos=false;
            }
            if(pos) printf("Yes\n");
            else printf("No\n");
        }
        else {
            int nz1=nz[l1];
            int nz2=nz[l2];
            int pz1=pz[l1+l-1];
            int pz2=pz[l2+l-1];
            if(nz1>=l1+l) {
                if(nz2>=l2+l) printf("Yes\n");
                else printf("No\n");
            }
            else {
                if(nz2>=l2+l) {
                    printf("No\n");
                    continue;
                }
                else {
                //cout<<l1<<" "<<nz1<<" "<<l2<<" "<<nz2<<" "<<pz1<<" "<<pz2<<endl;
                if((nz1-l1)%2!=(nz2-l2)%2) printf("No\n");
                else {
                    if((l1+l-pz1)%2!=(l2+l-pz2)%2) printf("No\n");
                    else {
                        int nh1=nv[nz1];
                        int nh2=nv[nz2];
                        int ph1=pv[pz1];
                        int ph2=pv[pz2];
                        int p1=0,p2=0;
                        //cout<<"ok"<<endl;
                        if(nh1==n+1 || nh1>=pz1) p1=n+1;
                        if(nh2==n+1 || nh2>=pz2) p2=n+1;
                        if(p1!=p2) printf("No\n");
                        else {
                            //cout<<"ok"<<p1<<" "<<p2<<endl;
                            if(p1==n+1 && p2==n+1) {
                                if(c[pz1]-c[nz1]!=c[pz2]-c[nz2]) printf("No\n");
                                else printf("Yes\n");
                            }
                            else {
                                if(c[nh1]-c[nz1]!=c[nh2]-c[nz2]) printf("No\n");
                                else {
                                    if(c[pz1]-c[ph1]!=c[pz2]-c[ph2]) printf("No\n");
                                    else {
                                        //cout<<"ok"<<endl;
                                        int v1,v2,v3,v4;
                                        v1=rv[nh1];
                                        v2=rv[nh2];
                                        v3=rv[ph1];
                                        v4=rv[ph2];
                                        //cout<<v1<<" "<<v2<<" "<<v3<<" "<<v4<<endl;
                                        if(v3-v1!=v4-v2) printf("No\n");
                                        else {
                                            if(fnd_has(v1,v3)!=fnd_has(v2,v4)) printf("No\n");
                                            else printf("Yes\n");
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                }
            }
        }
    }
    return 0;
}