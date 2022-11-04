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

const int N=109;
int T,n,a[N];

bool work(int k) {
    multiset<int,greater<int> >s;
    rep(i,1,n) s.insert(a[i]);
    rep(i,1,k) {
        while(s.size()&&*s.begin()>k-i+1) s.erase(s.begin());
        if(!s.size()) return 0;
        s.erase(s.begin());
        if(s.size()) {
            int x=*--s.end(); s.erase(--s.end());
            x+=k-i+1;
            s.insert(x);
        }
    }
    return 1;
}

signed main() {
    T=read();
    while(T--) {
        n=read();
        rep(i,1,n) a[i]=read();
        int l=0, r=1000000000, ans=-1;
        while(l<=r) {
            int mid=l+r>>1;
            if(work(mid)) ans=mid, l=mid+1;
            else r=mid-1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}