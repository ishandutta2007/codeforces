#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll k,n,w;
    cin>>k>>n>>w;
    for (ll i=1;i<=w;i++){
        n-=i*k;
    }
    if (n<0){
        cout<<-n<<endl;
    }
    else{
        cout<<0<<endl;
    }
}