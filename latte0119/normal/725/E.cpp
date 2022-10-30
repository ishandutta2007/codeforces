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

int C,N;
int cnt[222222];
int to[222222];
signed main(){
    scanf("%lld%lld",&C,&N);
    rep(i,N){
        int a;
        scanf("%lld",&a);
        cnt[a]++;
    }
    vector<pint>v;
    rep(i,222222)if(cnt[i])v.pb(pint(i,cnt[i]));

    memset(to,-1,sizeof(to));
    rep(i,v.size()){
        to[v[i].fi]=i;
    }
    for(int i=1;i<222222;i++)chmax(to[i],to[i-1]);

    for(int i=1;i<C;i++){
        int sum=C;
        int cur=v.size()-1;
        bool used=false;

        while(cur>=0){
            if(!used&&v[cur].fi<i){
                if(sum>=i)sum-=i;
                used=true;
            }
            int t=min(sum/v[cur].fi,v[cur].se);
            sum-=t*v[cur].fi;
            if(cur<=to[sum])cur--;
            else cur=to[sum];
        }

        if(sum==0)continue;
        cout<<i<<endl;
        return 0;
    }
    cout<<"Greed is good"<<endl;
    return 0;
}