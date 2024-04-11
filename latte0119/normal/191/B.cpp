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

int N,K;
int B;
int A[111111];

int sum[111111];
int r[111111];
signed main(){
    scanf("%lld%lld",&N,&K);
    scanf("%lld",&B);
    rep(i,N)scanf("%lld",&A[i]);

    vector<pint>ord;
    rep(i,N-1)ord.pb({A[i],i});
    sort(all(ord));reverse(all(ord));
    rep(i,N-1)r[ord[i].se]=i;


    int X=0;
    rep(i,K-1)X+=ord[i].fi;
    int Y=X+ord[K-1].fi;

    for(int i=0;i<N-1;i++){
        int tmp=X;
        if(r[i]<K-1)tmp=Y-A[i];

        if(tmp+A[i]>B){
            printf("%lld\n",i+1);
            return 0;
        }
    }
    cout<<N<<endl;
    return 0;
}