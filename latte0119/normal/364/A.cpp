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

int K;
string S;

int cnt[111111];

signed main(){
    cin>>K>>S;

    rep(i,S.size()){
        int s=0;
        for(int j=i;j<S.size();j++){
            s+=S[j]-'0';
            cnt[s]++;
        }
    }

    int ans=0;
    rep(i,111111){
        if(K==0){
            if(i==0)ans+=cnt[i]*S.size()*(S.size()+1)/2;
            else ans+=cnt[i]*cnt[0];
        }
        else{
            if(i==0||K%i||K/i>=111111)continue;
            ans+=cnt[i]*cnt[K/i];
        }
    }

    cout<<ans<<endl;
    return 0;
}