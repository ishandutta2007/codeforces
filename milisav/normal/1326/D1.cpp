#include<bits/stdc++.h>
#define maxn 2500000
using namespace std;
long long mod[2];
long long b[2];
long long step(long long x,long long y,int i) {
    if(y==0) return 1ll;
    if(y&1ll) return (x*step(x,y-1ll,i))%mod[i];
    else return step((x*x)%mod[i],y>>1ll,i);
}
long long inverse(long long x,int i) {
    return step(x,mod[i]-2,i);
}
long long deg[2][maxn];
long long invdeg[2][maxn];
int n;
char s[maxn];
char c[maxn];
long long hs[2][2][maxn];
int manc[maxn];
bool pos[maxn];
char o[maxn];
void precalc() {
    deg[0][0]=1;
    deg[1][0]=1;
    invdeg[0][0]=1;
    invdeg[1][0]=1;
    long long inv[2];
    inv[0]=inverse(b[0],0);
    inv[1]=inverse(b[1],1);
    for(int i=1;i<maxn;i++) {
        deg[0][i]=(deg[0][i-1]*b[0])%mod[0];
        deg[1][i]=(deg[1][i-1]*b[1])%mod[1];
        invdeg[0][i]=(invdeg[0][i-1]*inv[0])%mod[0];
        invdeg[1][i]=(invdeg[1][i-1]*inv[1])%mod[1];
    }
}
void hds() {
    for(int i=0;i<n;i++) {
        hs[0][0][i+1]=(hs[0][0][i]+c[i]*deg[0][i])%mod[0];
        hs[1][0][i+1]=(hs[1][0][i]+c[i]*deg[1][i])%mod[1];
    }
    for(int i=0;i<n;i++) {
        hs[0][1][i+1]=(hs[0][1][i]+c[n-1-i]*deg[0][i])%mod[0];
        hs[1][1][i+1]=(hs[1][1][i]+c[n-1-i]*deg[1][i])%mod[1];
    }
}
bool is_palin(int l,int r) {
    for(int i=0;i<2;i++) {
        long long v1=(hs[i][0][r+1]-hs[i][0][l])*invdeg[i][l];
        v1%=mod[i];
        if(v1<0) v1+=mod[i];
        long long v2=(hs[i][1][n-l]-hs[i][1][n-r-1])*invdeg[i][n-r-1];
        v2%=mod[i];
        if(v2<0) v2+=mod[i];
        if(v1!=v2) return false;

    }
    return true;
}
int main() {
    b[0]=1e6+7;
    b[1]=1e5+7;
    mod[0]=998244353;
    mod[1]=1e9+7;
    precalc();
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%s",s);
        n=strlen(s);
        c[0]='#';
        for(int i=0;i<n;i++) {
            c[2*i+1]=s[i];
            c[2*i+2]='#';
        }
        n=n*2+1;
        hds();
        for(int i=0;i<n;i++) {
            int l=1;
            int r=min(i+1,n-i);
            while(l<r) {
                int m=(l+r+1)>>1;
                if(is_palin(i-m+1,i+m-1)) l=m;
                else r=m-1;
            }
            manc[i]=l;
            //cout<<i<<" "<<manc[i]<<endl;
        }
        for(int i=0;i<n;i++) pos[i]=false;
        for(int i=0;2*i<n;i++) {
            if(c[i]!=c[n-1-i]) break;
            else pos[i]=true;
        }
        int bp=0;
        int id=0;
        for(int i=0;i<n;i++) {
            int t=min(i-manc[i],n-i-1-manc[i]);
            int cp=-1;
            if(t<0) {
                cp=manc[i]*2+1;
            }
            else {
                if(pos[t]) cp=manc[i]*2+1+(t+1)*2;
                else cp=-1;
            }
            //cout<<i<<" "<<cp<<" "<<bp<<endl;
            if(cp>bp) {
                bp=cp;
                id=i;
            }
        }
        int tv=min(id-manc[id],n-1-id-manc[id]);
        if(tv<0) {
            int l=0;
            for(int i=id-manc[id]+1;i<=id+manc[id]-1;i++) {
                if(c[i]!='#') o[l++]=c[i];
                o[l]=0;
            }
            printf("%s\n",o);
        }
        else {
            if(pos[tv]) {
                int l=0;
                if((id-manc[id])==tv) {
                    for(int i=0;i<=id;i++) {
                        if(c[i]!='#') o[l++]=c[i];
                        o[l]=0;
                    }
                    for(int i=id-1;i>=0;i--) {
                        if(c[i]!='#') o[l++]=c[i];
                        o[l]=0;
                    }
                }
                else {
                    for(int i=n-1;i>=id;i--) {
                        if(c[i]!='#') o[l++]=c[i];
                        o[l]=0;
                    }
                    for(int i=id+1;i<n;i++) {
                        if(c[i]!='#') o[l++]=c[i];
                        o[l]=0;
                    }
                }
                printf("%s\n",o);
            }
        }
    }
    return 0;
}