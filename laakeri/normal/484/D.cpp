#include <iostream>

using namespace std;

typedef long long ll;

ll a[1000001];

int main(){
    int n;
    cin>>n;
    ll mav=0;
    ll miv=0;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    ll mv=0;
    mav=a[0];
    miv=-a[0];
    for (int i=0;i<n;i++){
        ll v;
        //cout<<mav<<" "<<miv<<endl;
        v=max(mav-a[i], miv+a[i]);
        //cout<<v<<endl;
        mv=max(v, mv);
        if (i<n-1){
            miv=max(miv, v-a[i+1]);
            mav=max(mav, v+a[i+1]);
        }
    }
    cout<<mv<<endl;
}