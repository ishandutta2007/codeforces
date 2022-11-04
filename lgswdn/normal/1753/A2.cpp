#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define eb emplace_back
#define y1 yylyylyylyyl
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef unsigned long long ull;
 
long long read() {
    long long res=0, w=1; char c=getchar();
    while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
    while(isdigit(c)) {res=res*10+c-48, c=getchar();}
    return res*w;
}

const int N=200009;
int T,n,m,a[N],l[N],r[N],b[N];
vp ans;

signed main() {
    T=read();
    while(T--) {
        n=read();
        int cnt=0;
        rep(i,1,n) a[i]=read();
        rep(i,1,n) if(a[i]!=0) b[++cnt]=i;
        if(cnt%2==1) {
            puts("-1");
            continue;
        }
        if(cnt==0) {
            printf("%lld\n%lld %lld\n",1ll,1ll,n);
            continue;
        }
        ans.clear(); ans.shrink_to_fit();
        rep(i,1,cnt) if(a[b[i]]) {
            l[i]=r[i]=b[i];
            while(l[i]>1&&a[l[i]-1]==0) l[i]--;
            if(i==cnt) r[i]=n;
        }
        rep(i,1,cnt) if(i%2==1) {
            if((a[b[i]]==a[b[i+1]])^((b[i+1]-b[i])%2==0)) ans.eb(pii(l[i],r[i+1]));
            else {
                if(l[i]!=b[i]) ans.eb(pii(l[i],b[i]-1));
                ans.eb(pii(b[i],b[i])), ans.eb(pii(l[i+1],r[i+1]));
            }
        }
        int sz=ans.size();
        printf("%lld\n",sz);
        for(auto pp:ans) printf("%lld %lld\n",pp.fi,pp.se);
    }
    return 0;
}