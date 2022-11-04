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

const int N=2e5+9;
int T,n,k,a[N],id[N],b[N],sum;

bool cmp(const int &x,const int &y) {return a[x]+x>a[y]+y;}

signed main() {
    T=read();
    while(T--) {
        n=read(), k=read(); sum=0;
        rep(i,1,n) a[i]=read(), sum+=a[i];
        rep(i,1,n) id[i]=i;
        sort(id+1,id+n+1,cmp);
        rep(i,1,k) {
            if(a[id[i]]-n+id[i]+i-1<0) break;
            else sum-=(a[id[i]]-n+id[i]+i-1);
        }
        printf("%lld\n",sum);
    }  
    return 0;
}