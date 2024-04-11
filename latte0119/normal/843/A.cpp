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
int A[111111];

bool used[111111];
int pos[111111];

signed main(){
    cin>>N;
    rep(i,N)cin>>A[i];
    vint latte;
    rep(i,N)latte.pb(A[i]);
    sort(all(latte));
    rep(i,N)A[i]=lower_bound(all(latte),A[i])-latte.begin();
    rep(i,N)pos[A[i]]=i;


    vector<vint>ans;
    rep(i,N){
        if(used[i])continue;
        vint ei;
        int x=i;
        while(!used[x]){
            used[x]=true;
            ei.pb(x);
            x=A[x];
        }
        sort(all(ei));
        ans.pb(ei);
    }

    printf("%lld\n",(int)ans.size());
    rep(i,ans.size()){
        printf("%lld",(int)ans[i].size());
        rep(j,ans[i].size())printf(" %lld",ans[i][j]+1);
        puts("");
    }
    return 0;
}