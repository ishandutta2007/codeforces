#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
typedef vector<int>VI;

signed main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    cin>>N;
    int mi=1001001;
    int ans=0;
    rep(i,N){
        int a,p;
        cin>>a>>p;
        mi=min(mi,p);
        ans+=a*mi;
    }
    cout<<ans<<endl;

    return 0;
}