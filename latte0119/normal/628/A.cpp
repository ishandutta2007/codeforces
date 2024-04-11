#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define fi first
#define se second
#define each(i,c) for(auto i=(c).begin();i!=(c).end();i++)
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

signed main(){
    int n,b,p;
    cin>>n>>b>>p;

    int ans1=0,ans2=n*p;
    while(n>1){
        int k=1;
        while(k*2<=n)k*=2;
        ans1+=k/2*(b*2+1);
        n-=k/2;
    }

    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}