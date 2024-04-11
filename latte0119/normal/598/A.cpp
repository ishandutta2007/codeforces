#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
typedef vector<int>vint;
typedef pair<int,int>pint;


signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int p=0;
        while((1ll<<p)<=n)p++;
        cout<<n*(n+1)/2-2*((1<<p)-1)<<endl;
    }
    return 0;
}