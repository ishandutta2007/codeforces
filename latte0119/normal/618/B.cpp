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

int n;
int a[50][50];

signed main(){
    cin>>n;
    rep(i,n)rep(j,n)cin>>a[i][j];
    int ans[50];
    rep(i,n)ans[i]=*max_element(a[i],a[i]+n);
    rep(i,n)if(ans[i]==n-1){
        ans[i]++;
        break;
    }
    rep(i,n)cout<<ans[i]<<" ";cout<<endl;
    return 0;
}