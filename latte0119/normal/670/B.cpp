#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int n,m;
int a[100000];

signed main(){
    scanf("%lld%lld",&n,&m);
    rep(i,n)scanf("%lld",&a[i]);

    for(int i=1;i<=n;i++){
        if(m<=i)break;
        m-=i;
    }

    printf("%lld\n",a[m-1]);
    return 0;
}