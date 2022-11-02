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

signed main(){
    int n,m;
    int N,M;
    string A,B;
    cin>>n>>m>>A>>B;
    N=A.size();M=B.size();

    int L=0;
    vector<int>used(M);

    vector<vint>latte;
    while(L<N&&!used[L]){
        vint cnt(26);
        int x=0;
        while(true){
            cnt[B[(x+L)%M]-'a']++;
            used[(x+L)%M]=1;
            x=(x+N)%M;
            if(x==0)break;
        }
        latte.pb(cnt);
        L++;
    }

    int ans=0;
    for(int i=0;i<N;i++){
        ans+=latte[i%L][A[i]-'a'];
    }


    int l=accumulate(all(latte[0]),0ll);
    ans*=n/l;

    ans=n*A.size()-ans;
    cout<<ans<<endl;
    return 0;
}