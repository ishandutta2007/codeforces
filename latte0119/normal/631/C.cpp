#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define pb push_back
#define fi first
#define se second;
#define all(v) (v).begin(),(v).end()
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int SIZE=200000;

int N,Q;
int A[SIZE];
int T[SIZE],B[SIZE+1];

signed main(){
    scanf("%lld%lld",&N,&Q);
    rep(i,N)scanf("%lld",&A[i]);

    vint ord;
    rep(i,Q){
        scanf("%lld%lld",&T[i],&B[i]);
        while(ord.size()&&B[ord.back()]<=B[i])ord.pop_back();
        if(ord.size()==0||T[ord.back()]!=T[i])ord.pb(i);
    }

    vint ans;
    int l=0,r=N;
    bool rev=false;
    while(r>B[ord.front()]){
        r--;
        ans.pb(A[r]);
    }

    sort(A,A+B[ord.front()]);
    if(T[ord.front()]==2){
        rev=true;
    }

    ord.erase(ord.begin());
    ord.pb(Q);

    rep(i,ord.size()){
        while(r-l>B[ord[i]]){
            if(rev)ans.pb(A[l++]);
            else ans.pb(A[--r]);
        }
        rev=!rev;
    }

    rep(i,ans.size())printf("%lld ",ans[N-1-i]);
    puts("");
    return 0;
}