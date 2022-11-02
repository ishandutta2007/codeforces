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
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

signed main(){
    int n,p;cin>>n>>p;

    int ans=0;
    int v=0;
    bool a[114]={0};
    rep(i,n){
        string s;cin>>s;if(s=="half")a[i]=true;
    }

    for(int i=n-1;i>=0;i--){
        if(a[i]){
            ans+=v*p;
            v*=2;
        }
        else{
            ans+=v*p+p/2;
            v=v*2+1;
        }
    }
    cout<<ans<<endl;

    return 0;
}