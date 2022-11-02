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

int N;
vint v1,v2;
signed main(){
    cin>>N;
    rep(i,N){
        int t,w;
        cin>>t>>w;
        if(t==1)v1.pb(w);
        else v2.pb(w);
    }
    sort(v1.rbegin(),v1.rend());
    sort(v2.rbegin(),v2.rend());

    int mi=1001001001;
    for(int i=0;i<=v1.size();i++){
        for(int j=0;j<=v2.size();j++){
            int tt=i+j*2;
            int tw=accumulate(v1.begin()+i,v1.end(),0ll)+accumulate(v2.begin()+j,v2.end(),0ll);
            if(tw<=tt)chmin(mi,tt);
        }
    }
    printf("%lld\n",mi);
    return 0;
}