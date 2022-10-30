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

int N;
string S,T;
signed main(){
    cin>>N>>S>>T;
    sort(all(S));sort(all(T));

    int cur=0,ans=0;
    rep(i,S.size()){
        while(cur<N&&S[i]>T[cur])cur++;
        if(cur!=N){
            cur++;
        }
        else{
            ans++;
        }
    }
    cout<<ans<<endl;

    cur=0;ans=0;
    rep(i,S.size()){
        while(cur<N&&S[i]>=T[cur])cur++;
        if(cur!=N){
            cur++;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}