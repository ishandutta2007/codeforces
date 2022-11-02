#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,f,n) for(int i=(int)(f);i<(int)(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

struct CHT{
    vpint ls;

    bool check(pint l1,pint l2,pint l3){
        return (l3.first-l2.first)*(l2.second-l1.second)<=(l2.first-l1.first)*(l3.second-l2.second);
    }

    void add(int a,int b){
        pint l(a,b);
        while(ls.size()>=2&&check(ls[ls.size()-2],ls[ls.size()-1],l))ls.pop_back();
        ls.pb(l);
    }

    int f(int k,int x){
        return ls[k].first*x+ls[k].second;
    }

    int query(int x){
        assert(ls.size());
        int lb=-1,ub=ls.size()-1;
        while(ub-lb>1){
            int mid=(ub+lb)/2;
            if(f(mid,x)<=f(mid+1,x))lb=mid;
            else ub=mid;
        }
        return f(ub,x);
    }
};

const int SIZE=200000;
int N;
int A[SIZE],S[SIZE];

signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&A[i]);

    int ans=0,base=0;
    rep(i,N)base+=(i+1)*A[i];
    rep(i,N)S[i]=(i?S[i-1]:0)+A[i];
    CHT cht1;
    for(int i=N-1;i>=0;i--){
        cht1.add(-i-1,-S[i]);
        chmax(ans,cht1.query(-A[i])-A[i]*(i+1)+S[i]);
    }

    S[0]=0;
    rep(i,N)S[i+1]=S[i]+A[i];
    CHT cht2;
    rep(i,N){
        cht2.add(i+1,-S[i]);
        chmax(ans,cht2.query(A[i])+S[i]-A[i]*(i+1));
    }
    cout<<base+ans<<endl;
    return 0;
}