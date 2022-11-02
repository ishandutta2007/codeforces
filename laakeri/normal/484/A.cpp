#include <iostream>

using namespace std;

typedef long long ll;

int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        ll l, r;
        cin>>l>>r;
        ll v=0;
        for (ll ii=62;ii>=0;ii--){
            if (v+(1ll<<ii)-1ll>=l&&v+(1ll<<ii)-1ll<=r){
                v+=(1ll<<ii)-1ll;
                break;
            }
            else if (v+(1ll<<ii)-1ll<=r){
                v+=(1ll<<ii);
            }
        }
        cout<<v<<'\n';
    }
}