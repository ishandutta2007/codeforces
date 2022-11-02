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
int a[1111];
int b[1111];

signed main(){
    cin>>N;
    rep(i,N)cin>>a[i];
    rep(i,N)cin>>b[i];

    int aa=0,bb=0;
    rep(i,N)aa|=a[i];
    rep(i,N)bb|=b[i];
    cout<<aa+bb<<endl;
    return 0;
}