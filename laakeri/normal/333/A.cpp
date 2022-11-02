#include <iostream>

using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin>>n;
    ll v=1;
    for (ll a=1;a<n;a*=3ll){
        if (n%a>0){
            v=max(v, n/a+1);
        }
    }
    cout<<v<<endl;
}