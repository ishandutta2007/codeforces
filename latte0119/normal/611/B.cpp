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
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}



signed main(){
    int A,B;cin>>A>>B;
    int ans=0;
    for(int len=1;len<=60;len++){
        for(int i=1;i<len;i++){
            int b=0;
            for(int j=0;j<len;j++){
                if(j+1==i)continue;
                b+=(1ll<<j);
            }
            if(A<=b&&b<=B)ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}