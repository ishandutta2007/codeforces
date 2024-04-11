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

int N,M;
int A[111][4];
signed main(){
    cin>>N>>M;
    int c=1;
    rep(i,N){
        A[i][0]=c++;
        A[i][3]=c++;
    }
    rep(i,N){
        A[i][1]=c++;
        A[i][2]=c++;
    }

    vint ans;
    rep(i,N){
        ans.pb(A[i][1]);
        ans.pb(A[i][0]);
        ans.pb(A[i][2]);
        ans.pb(A[i][3]);
    }

    rep(i,ans.size())if(ans[i]<=M)cout<<ans[i]<<" ";cout<<endl;
    return 0;
}