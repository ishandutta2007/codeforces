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

const int N=2e5+9;
int T,n;
char s[N];

int nxt(int i) {return i==n?1:i+1;}
int lst(int i) {return i==1?n:i-1;}

signed main() {
    T=read();
    while(T--) {
        n=read(); scanf("%s",s+1);
        int x=0;
        rep(i,1,n) if(s[i]=='1') x++;
        if(x==0||x%2==1) {
            puts("NO");
        } else if(x==n) {
            puts("YES");
            rep(i,2,n) printf("1 %lld\n",i);
        } else {
            puts("YES");
            int r=0;
            rep(i,1,n) if(s[i]=='0'&&s[lst(i)]=='1') {r=i; break;}
            for(int i=nxt(r);i!=r;i=nxt(i)) {
                if(s[lst(i)]=='1') printf("%lld %lld\n",r,i);
                else printf("%lld %lld\n",lst(i),i);
            }
        }
    }
    return 0;
}