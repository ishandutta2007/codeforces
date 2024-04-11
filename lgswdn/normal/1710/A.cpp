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
int a[N];

signed main() {
    int T=read();
    while(T--) {
        int n=read(), m=read(), k=read();
        rep(i,1,k) a[i]=read();
        int cnt=0;
        bool flag=0;
        rep(i,1,k) {
            if(a[i]/n>2) cnt+=a[i]/n, flag=1;
            else if(a[i]/n==2) {
                if(cnt+1==m&&!flag) continue;
                else cnt+=2;
            }
        }
        if(cnt>=m) {puts("Yes"); continue;}
        cnt=0, flag=0;
        rep(i,1,k) {
            if(a[i]/m>2) cnt+=a[i]/m, flag=1;
            else if(a[i]/m==2) {
                if(cnt+1==n&&!flag) continue;
                else cnt+=2;
            }
        }
        if(cnt>=n) {puts("Yes"); continue;}
        puts("No");
    }
    return 0;
}