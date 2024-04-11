#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int gcd(int a,int b){
    int tmp;
    while(b){
        tmp=a%b;
        a=b;
        b=tmp;
    }
    return a;
}


int N;
int A[555555];


const int SEG=1<<19;
int dat[SEG*2];
void build(){
    rep(i,N)dat[i+SEG-1]=A[i];
    for(int i=SEG-2;i>=0;i--)dat[i]=gcd(dat[i*2+1],dat[i*2+2]);
}
void update(int k,int a){
    k+=SEG-1;
    dat[k]=a;
    while(k){
        k=(k-1)/2;
        dat[k]=gcd(dat[k*2+1],dat[k*2+2]);
    }
}

int queryL(int a,int b,int x,int k=0,int l=0,int r=SEG){
    if(r<=a||b<=l)return -1;
    if(l+1==r){
        if(dat[k]%x==0)return r;
        return l;
    }
    if(a<=l&&r<=b){
        if(dat[k]%x==0)return r;
        if(dat[k*2+1]%x==0)return queryL(a,b,x,k*2+2,(l+r)/2,r);
        return queryL(a,b,x,k*2+1,l,(l+r)/2);
    }

    int tmp=queryL(a,b,x,k*2+1,l,(l+r)/2);
    if(tmp!=-1&&tmp!=(l+r)/2)return tmp;
    tmp=queryL(a,b,x,k*2+2,(l+r)/2,r);
    if(tmp==-1)return (l+r)/2;
    return tmp;
}

int queryR(int a,int b,int x,int k=0,int l=0,int r=SEG){
    if(r<=a||b<=l)return -1;
    if(l+1==r){
        if(dat[k]%x==0)return l;
        return r;
    }
    if(a<=l&&r<=b){
        if(dat[k]%x==0)return l;
        if(dat[k*2+2]%x==0)return queryR(a,b,x,k*2+1,l,(l+r)/2);
        return queryR(a,b,x,k*2+2,(l+r)/2,r);
    }

    int tmp=queryR(a,b,x,k*2+2,(l+r)/2,r);
    if(tmp!=-1&&tmp!=(l+r)/2)return tmp;
    tmp=queryR(a,b,x,k*2+1,l,(l+r)/2);
    if(tmp==-1)return (l+r)/2;
    return tmp;
}

signed main(){
    scanf("%lld",&N);
    rep(i,N){
        scanf("%lld",&A[i]);
    }

    build();

    int Q;scanf("%lld",&Q);
    while(Q--){
        int t;scanf("%lld",&t);
        if(t==1){
            int l,r,x;
            scanf("%lld%lld%lld",&l,&r,&x);
            l--;
            int s=queryL(l,r,x);
            int t=queryR(l,r,x);
            if(t-s<=1)puts("YES");
            else puts("NO");
        }
        else{
            int a,b;
            scanf("%lld%lld",&a,&b);
            a--;
            update(a,b);
        }
    }
    return 0;
}