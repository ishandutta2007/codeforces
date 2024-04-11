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
template<typename A,typename B>inline void chmin(A &a,B &b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B &b){if(a<b)a=b;}

signed main(){
    int n,m;
    cin>>n>>m;

    int a[5]={};
    int b[5]={};
    for(int i=1;i<=n;i++)a[i%5]++;
    for(int i=1;i<=m;i++)b[i%5]++;
    int ans=0;
    for(int i=0;i<5;i++)ans+=a[i]*b[(5-i)%5];
    cout<<ans<<endl;
    return 0;
}