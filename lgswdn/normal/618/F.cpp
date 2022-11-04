#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

long long read() {
    long long res=0, w=1; char c=getchar();
    while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
    while(isdigit(c)) {res=res*10+c-48, c=getchar();}
    return res*w;
}

const int N=1e6+9;
int n,a[N],b[N],p[N],c[N];
bool sw;

signed main() {
    n=read();
    rep(i,1,n) a[i]=read(), a[i]+=a[i-1];
    rep(i,1,n) b[i]=read(), b[i]+=b[i-1];
    if(a[n]>b[n]) {
        sw=1;
        rep(i,1,n) swap(a[i],b[i]);
    }
    rep(i,1,n) {
        p[i]=p[i-1];
        while(p[i]<=n&&b[p[i]]<=a[i]) p[i]++; p[i]--;
    }
    c[0]=0;
    rep(i,1,n) {
        if(a[i]-b[p[i]]==0||c[a[i]-b[p[i]]]) {
            int pos=c[a[i]-b[p[i]]];
            if(!sw) {
                printf("%d\n",i-pos);
                rep(j,pos+1,i) printf("%d ",j); puts("");
                printf("%d\n",p[i]-p[pos]);
                rep(j,p[pos]+1,p[i]) printf("%d ",j); puts("");
            } else {
                printf("%d\n",p[i]-p[pos]);
                rep(j,p[pos]+1,p[i]) printf("%d ",j); puts("");
                printf("%d\n",i-pos);
                rep(j,pos+1,i) printf("%d ",j); puts("");
            }
            return 0;
        } else c[a[i]-b[p[i]]]=i;
    }
    return 0;
}