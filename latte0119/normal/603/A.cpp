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

const int INF=1001001001001001001ll;
const int mod=1000000009;

template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}
template<class T,class U>void chadd(T &t,U f){t=(t+f)%mod;}

signed main(){
    int N;string S;
    cin>>N>>S;
    int ret=1,same=0;

    reps(i,1,N){
        if(S[i]!=S[i-1])ret++;
        else same++;
    }

    cout<<ret+min(2ll,same)<<endl;

    return 0;
}