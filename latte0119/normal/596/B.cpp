#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

const int MN=200000;

int N;
int b[MN];

signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&b[i]);
    int cur=0,ans=0;
    rep(i,N){
        ans+=abs(cur-b[i]);
        cur=b[i];
    }
    printf("%lld\n",ans);

    return 0;
}