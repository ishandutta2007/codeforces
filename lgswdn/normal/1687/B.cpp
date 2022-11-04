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

const int N=509;
int w[N],id[N],n,m,mx,ans;
char s[N];

bool cmp(const int &a,const int &b) {
    return w[a]>w[b];
}

int qry(int a) {
    putchar('?'); putchar(' ');
    if(a==0) {
        rep(i,1,m) putchar('1');
    } else {
        rep(i,1,m) putchar(s[i]);
    }
    puts("");
    fflush(stdout);
    return read();
}

signed main() {
    n=read(), m=read();
    mx=qry(0);
    rep(i,1,m) {
        rep(j,1,m) {
            if(i==j) s[j]='1';
            else s[j]='0';
        }
        w[i]=qry(1);
    }
    rep(i,1,m) id[i]=i;
    sort(id+1,id+m+1,cmp);
    rep(i,1,m) s[i]='1';
    rep(i,1,m-1) {
        int x=id[i];
        s[x]='0';
        int nm=qry(1);
        if(mx-nm==w[id[i]]) ans+=w[id[i]];
        mx=nm;
    }
    printf("! %lld\n",ans+w[id[m]]);
    fflush(stdout);
    return 0;
}