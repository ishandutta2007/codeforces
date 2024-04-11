#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

const int mod=1000000007;

int P,K;
int to[1000000];
int t[1000000];

int mod_pow(int n,int m,int x){
    int ret=1;
    while(m){
        if(m&1)ret=ret*n%x;
        n=n*n%x;
        m>>=1;
    }
    return ret;
}

signed main(){
    cin>>P>>K;

    rep(i,P)to[i]=K*i%P;
    fill_n(t,P,-1);

    if(K==0){
        cout<<mod_pow(P,P-1,mod)<<endl;
        return 0;
    }

    int latte=mod_pow(K,P-2,P);

    int cur=0,ans=1;
    rep(i,P){
        if(t[i]!=-1)continue;
        int s=cur;
        int v=i;
        while(true){
            if(t[v]==-1)t[v]=cur++;
            else{
                if(t[v]>=s&&mod_pow(latte,cur-t[v],P)==1)ans=ans*P%mod;
                break;
            }
            v=to[v];
        }
    }
    cout<<ans<<endl;
    return 0;
}