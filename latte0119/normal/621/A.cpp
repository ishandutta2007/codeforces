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
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

signed main(){
    int n;cin>>n;
    vint e,o;
    rep(i,n){
        int a;cin>>a;
        if(a&1)o.pb(a);
        else e.pb(a);
    }

    sort(all(o));reverse(all(o));
    if(o.size()&1)o.pop_back();
    cout<<accumulate(all(e),0ll)+accumulate(all(o),0ll)<<endl;
    return 0;
}