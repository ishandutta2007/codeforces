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

const int N=1e5+9;
int T,n;

int work(vi a,int cnt) {
    int n=a.size()-1;
    if(n==0) return 0;
    else if(n==1) return a[1];
    vi b(1); b[0]=0;
    bool flag=(cnt>0);
    rep(i,(cnt?1:2),n) {
        int d=a[i]-a[i-1];
        if(d) b.emplace_back(d);
        else cnt++;
    }
    sort(b.begin(),b.end());
    if(flag) cnt--;
    return work(b,cnt);
}

signed main() {
    T=read();
    while(T--) {
        n=read();
        vi a(1); a[0]=0; int c=0;
        rep(i,1,n) {
            int x=read();
            if(x) a.emplace_back(x);
            else c++;
        }
        printf("%lld\n",work(a,c));
    }
    return 0;
}