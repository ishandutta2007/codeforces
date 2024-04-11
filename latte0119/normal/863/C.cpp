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

pint operator+(pint p,pint q){
    return {p.fi+q.fi,p.se+q.se};
}

int K,a1,b1;
int A[3][3],B[3][3];

pint score(int a,int b){
    if(a==b)return {0,0};
    if((a-b+3)%3==1)return {1,0};
    return {0,1};
}

int nex[66][9];
pint val[66][9];

signed main(){
    cin>>K>>a1>>b1;

    rep(i,3)rep(j,3)cin>>A[i][j];
    rep(i,3)rep(j,3)cin>>B[i][j];

    rep(i,3)rep(j,3){
        int ni=A[i][j]-1; 
        int nj=B[i][j]-1;
        nex[0][i*3+j]=ni*3+nj;
        val[0][i*3+j]=score(i,j); 
    }

    rep(k,60){
        rep(i,9){
            nex[k+1][i]=nex[k][nex[k][i]];
            val[k+1][i]=val[k][i]+val[k][nex[k][i]];
        }
    }
    int st=(a1-1)*3+(b1-1);
    pint ans;

    rep(k,60)if(K>>k&1){
        ans=ans+val[k][st];
        st=nex[k][st];
    }

    cout<<ans.fi<<" "<<ans.se<<endl;
    return 0;
}