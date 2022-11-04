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

const int N=1e6+9;
int n,x,a[N],c[N];

signed main() {
    n=read(), x=read();
    rep(i,1,n) a[i]=read(), c[a[i]]++;
    rep(i,1,x-1) {
        if(c[i]%(i+1)) return puts("No"), 0;
        c[i+1]+=c[i]/(i+1);
    }
    puts("Yes");
    return 0;
}