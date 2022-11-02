#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
    ost<<"{"<<p.first<<","<<p.second<<"}";
    return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
    ost<<"{";
    for(int i=0;i<v.size();i++){
        if(i)ost<<",";
        ost<<v[i];
    }
    ost<<"}";
    return ost;
}

inline int topbit(unsigned long long x){
    return x?63-__builtin_clzll(x):-1;
}

inline int popcount(unsigned long long x){
    return __builtin_popcountll(x);
}

inline int parity(unsigned long long x){
    return __builtin_parity(x);
}

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

void extgcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1;
        y=0;    
    }
    else{
        extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
}

//ceil(a/b)
int ce(int a,int b){
    if(a>=0)return (a+b-1)/b;
    return a/b;
}

//floor(a/b)
int fl(int a,int b){
    if(a>=0)return a/b;
    return (a-(b-1))/b;
}


signed main(){
    int a1,b1,a2,b2,L,R;
    cin>>a1>>b1>>a2>>b2>>L>>R;
    int g=gcd(a1,a2);

    int r1=(b1%g+g)%g;
    int r2=(b2%g+g)%g;

    if(r1!=r2){
        cout<<0<<endl;
        return 0;
    }

    L-=r1;
    R-=r1;

    a1/=g;
    a2/=g;
    b1=(b1-r1)/g;
    b2=(b2-r2)/g;

    L=ce(L,g);
    R=fl(R,g);

    if(L>R){
        cout<<0<<endl;
        return 0;
    }

    /*
        gcd(a1,a2)==1
    */

    chmax(L,b1);
    chmax(L,b2);

    int s,t;
    extgcd(a1,a2,s,t);

    int m=a1*a2;
    int b=((__int128)s*a1%m*b2+(__int128)t*a2%m*b1)%m;
    b=(b+m)%m;

    b=(b%m+m)%m;

    L-=b;
    R-=b;

    L=ce(L,m);
    R=fl(R,m);

    if(L>R){
        cout<<0<<endl;
    }
    else{
        cout<<R-L+1<<endl;
    }
    return 0;
}