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

const int N=59;
int T,n,m;
char s[N],t[N];

signed main() {
    int T=read();
    while(T--) {
        n=read(), m=read();
        scanf("%s%s",s+1,t+1);
        bool flag=1;
        rep(i,0,m-2) {
            if(t[m-i]!=s[n-i]) flag=0;
        }
        if(flag==0) {puts("NO"); continue;}
        flag=0;
        rep(j,1,n-m+1) if(s[j]==t[1]) flag=1;
        if(flag) puts("YES");
        else puts("NO");
    }
    return 0;
}