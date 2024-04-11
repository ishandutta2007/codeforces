#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N;
int A[111111];

int ans;

void solve(){
    deque<int>d;

    rep(i,N){
        int l=0;
        int r=lower_bound(all(d),A[i])-d.begin();

        if(r!=0){
            for(int j=29;j>=0;j--){
                int lb=l-1,ub=r;
                while(ub-lb>1){
                    int mid=(ub+lb)/2;
                    if(d[mid]>>j&1)ub=mid;
                    else lb=mid;
                }

                if(ub==l||ub==r)continue;
                if(A[i]>>j&1)r=ub;
                else l=ub;
            }
            assert(r-l>=1&&l<d.size());
            chmax(ans,d[l]^A[i]);
        }

        while(d.size()&&d.front()<A[i])d.pop_front();
        d.push_front(A[i]);
    }

}

signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&A[i]);

    rep(i,2){
        solve();
        reverse(A,A+N);
    }
    cout<<ans<<endl;
    return 0;
}