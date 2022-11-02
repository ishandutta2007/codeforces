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

int a[1111111];
int n;
signed main(){
    scanf("%lld",&n);
    for(int i=0;i*2+1<n;i++){
        a[i]=a[n-1-i]=i*2+1;
    }
    for(int i=0;2*(i+1)<n;i++){
        a[n+i]=a[2*n-2-i]=2*(i+1);
    }

    for(int i=0;i<2*n;i++)if(a[i]==0)a[i]=n;
    for(int i=0;i<2*n;i++)printf("%lld ",a[i]);
    puts("");
    return 0;
}