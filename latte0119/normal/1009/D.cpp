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

int N,M;
vint G[111111];
void addEdge(int a,int b){
    if(M)G[a].pb(b),M--;
}
signed main(){
    cin>>N>>M;
    if(M<N-1){
        puts("Impossible");
        return 0;
    }
    for(int i=2;i<=N;i++)addEdge(1,i);
    for(int i=2;i<=N&&M;i++){
        vint lis;
        int n=i;
        int s=-1;
        for(int j=2;j*j<=n;j++){
            if(n%j)continue;
            n/=j;
            lis.pb(j);
            if(n%j==0){
                s=j;
                break;
            }
        }

        int uku=1001001001;
        if(n!=1)lis.pb(n);
        if(s!=-1){
            n=i/s;
        }
        else{
            n=i/lis.back();
            uku=lis.back();
        }
        for(int k=(int)G[n].size()-1;k>=0&&G[n][k]>i;k--){
            if(G[n][k]%uku)addEdge(i,G[n][k]);
        }
        reverse(all(G[i]));
    }

    if(M){
        puts("Impossible");
    }
    else{
        puts("Possible");
        for(int i=1;i<=N;i++){
            for(auto u:G[i]){
                printf("%lld %lld\n",i,u);
            }
        }
    }
    return 0;
}