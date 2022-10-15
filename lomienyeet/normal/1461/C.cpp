#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define ff first
#define ss second
void eat(){
    int n,m;
    cin>>n>>m;
    int arr[n+1],s=0;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=n;i>0;i--){
        if(arr[i]!=i){
            s=i;
            break;
        }
    }
    double fuck=1;
    pair<int,double> p[m+1];
    for(int i=1;i<=m;i++){
        cin>>p[i].ff>>p[i].ss;
        if(p[i].ff>=s)fuck*=(1-p[i].ss);
    }
    // bruh
    if(!s)cout<<"1\n";
    else cout<<fixed<<setprecision(6)<<1-fuck<<"\n";
    return;
}
signed main(){
    int t;
    cin>>t;
    while(t--)eat();
}