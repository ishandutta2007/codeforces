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

const int N=3e5+9;
int n,q,a[N],sum;

int calc() {
    int x=(a[1]+sum)>>1;
    //cout<<a[1]<<" "<<sum<<endl;
    return max(x,a[1]-x+sum);
}

signed main() {
    n=read();
    rep(i,1,n) a[i]=read();
    per(i,n,2) a[i]=a[i]-a[i-1];
    rep(i,2,n) if(a[i]>0) sum+=a[i];
    printf("%lld\n",calc());
    q=read();
    rep(i,1,q) {
        int l=read(), r=read(), x=read();
        if(l==1) a[1]+=x;
        else {
            if(a[l]>0) sum-=a[l];
            a[l]+=x;
            if(a[l]>0) sum+=a[l];
        }
        if(r<n) {
            if(a[r+1]>0) sum-=a[r+1];
            a[r+1]-=x;
            if(a[r+1]>0) sum+=a[r+1];
        }
        printf("%lld\n",calc());
    }   
    return 0;
}