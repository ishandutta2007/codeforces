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

int N;
int A[1111];

bool f[1111];
vint prime;

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

signed main(){
    fill_n(f,1111,true);
    f[0]=f[1]=false;
    for(int i=2;i<1111;i++){
        if(!f[i])continue;
        prime.pb(i);
        for(int j=i+i;j<1111;j+=i)f[j]=false;
    }

    cin>>N;
    rep(i,N)cin>>A[i];
    vint ans;
    ans.pb(A[0]);
    reps(i,1,N){
        int g=gcd(ans.back(),A[i]);
        if(g!=1){
            for(auto p:prime){
                if(ans.back()%p&&A[i]%p){
                    ans.pb(p);
                    break;
                }
            }
        }
        ans.pb(A[i]);
    }

    cout<<ans.size()-N<<endl;
    rep(i,ans.size())cout<<ans[i]<<" ";cout<<endl;
    return 0;
}