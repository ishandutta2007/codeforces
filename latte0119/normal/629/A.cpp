#include<bits/stdc++.h>
using namespace std;

//#define int long long

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
char fld[111][111];

signed main(){
    cin>>N;
    rep(i,N)cin>>fld[i];

    int ans=0;
    rep(i,N)rep(j,N){
        if(fld[i][j]!='C')continue;
        for(int k=i+1;k<N;k++)if(fld[k][j]=='C')ans++;
        for(int k=j+1;k<N;k++)if(fld[i][k]=='C')ans++;
    }
    cout<<ans<<endl;
    return 0;
}