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

const int N=1e5+9;
int n,m,a[N],b[N],ans=-1;

bool check(int x) {
    rep(i,1,n) b[i]=a[i]; int pos=n;
    rep(i,1,m) {
        while(pos&&!b[pos]) pos--;
        if(pos>=x) return 0;
        if(pos==0) return 1;
        int y=x-pos;
        while(pos) {
            if(y>=b[pos]) y-=b[pos], b[pos]=0, pos--;
            else {b[pos]-=y; break;}
        }
    }
    if(pos) return 0;
    else return 1;
}

signed main() {
    n=read(), m=read();
    int l=0,r=0;
    rep(i,1,n) a[i]=read(), r+=a[i]+i;
    while(l<=r) {
        int mid=l+r>>1;
        if(check(mid)) ans=mid, r=mid-1;
        else l=mid+1;
    }
    printf("%lld\n",ans);
    return 0;
}