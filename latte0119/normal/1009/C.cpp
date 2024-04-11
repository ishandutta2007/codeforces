#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,a,b) for(int i=(a);i<(b);i++)
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

signed main(){
    int N,M;
    cin>>N>>M;

    int sum=0;
    rep(i,M){
        int x,d;
        cin>>x>>d;
        sum+=x*N;

        if(d<0){
            int n=(N-1)/2;
            int nn=N-1-n;
            sum+=(n*(n+1)/2+nn*(nn+1)/2)*d;
        }
        else{
            sum+=N*(N-1)/2*d;
        }
    }
    printf("%.20f\n",1.0*sum/N);
    return 0;
}