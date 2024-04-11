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



int N;
int A[111111],B[111111];

vint ans;
int where[111111];
bool used[111111];
signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&A[i]);
    rep(i,N)scanf("%lld",&B[i]);

    vector<pair<pint,int>>luz;
    rep(i,N){
        luz.pb({pint(A[i],B[i]),i});
    }
    sort(all(luz));

    rep(i,N){
        tie(A[i],B[i])=luz[i].fi;
        where[i]=luz[i].se;
    }

    stack<pint>stk;
    rep(i,N){
        if(stk.size()==0||stk.top().fi>B[i]){
            stk.push({B[i],i});
            continue;
        }
        ans.pb(i);
        used[i]=true;
        used[stk.top().se]=true;
        stk.pop();
    }

    vint lis;
    rep(i,N)if(!used[i])lis.pb(i);

    if(lis.size()==0){
        rep(i,N){
            if(binary_search(all(ans),i))continue;
            ans.pb(i);
            break;
        }
    }
    else{
        for(int i=0;i<lis.size();i+=2)ans.pb(lis[i]);
        if(lis.size()%2==0)ans.pb(lis.back());
    }

    printf("%lld\n",(int)ans.size());
    rep(i,ans.size())printf("%lld ",where[ans[i]]+1);
    puts("");
    return 0;
}