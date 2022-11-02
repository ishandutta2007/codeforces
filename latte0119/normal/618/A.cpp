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

vint vec;

signed main(){
    vec.pb(1);
    int n;cin>>n;
    rep(i,n-1){
        vec.pb(1);
        while(vec.size()>1&&vec[vec.size()-2]==vec[vec.size()-1]){
            vec.pop_back();
            vec[vec.size()-1]++;
        }
    }

    rep(i,vec.size())cout<<vec[i]<<" ";cout<<endl;
    return 0;
}