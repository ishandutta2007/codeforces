#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin>>n;
    vector<ll>ls(n);
    for (int i=0;i<n;i++) cin>>ls[i];
    sort(ls.begin(), ls.end());
    ll v=0;
    for (ll i=0;i<n;i++){
        if (i<n-1) v+=(i+2ll)*ls[i];
        else v+=(i+1ll)*ls[i];
    }
    cout<<v<<endl;
}