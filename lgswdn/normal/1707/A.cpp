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
typedef unsigned long long ull;
typedef bitset<509> bset;
typedef pair<bset,bset> v2;

long long read() {
    long long res=0, w=1; char c=getchar();
    while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
    while(isdigit(c)) {res=res*10+c-48, c=getchar();}
    return res*w;
}

const int N=1e6+9;
int T,n,q,a[N],b[N],c[N];
char s[N];

bool check(int k) {
    int p=q;
    int cnt=0;
    rep(i,1,n) c[i]=(a[i]<=p), cnt+=(a[i]<=p);
    per(i,n,1) {
        if(cnt>=k) break;
        if(c[i]==0) c[i]=1, cnt++;
    }
    rep(i,1,n) if(c[i]) {
        if(p<=0) return 0;
        p-=(p<a[i]);
    }
    return 1;
}

signed main() {
    T=read();
    while(T--) {
        n=read(), q=read();
        rep(i,1,n) a[i]=read();
        int l=1,r=n,res=-1;
        while(l<=r) {
            int mid=l+r>>1;
            if(check(mid)) res=mid, l=mid+1;
            else r=mid-1;
        }
        check(res);
        rep(i,1,n) putchar('0'+c[i]);
        puts("");
    }
    return 0;
}