#include <iostream>

using namespace std;

typedef long long ll;

ll cost(ll le, ll ri, ll lc, ll rc){
    if (le<ri){
        return cost(ri, le, rc, lc);
    }
    if (ri==le){
        return 0;
    }
    return (le-1ll-ri)*lc;
}

ll a[100001];

int main(){
    ll n,l,r,q1,q2;
    cin>>n>>l>>r>>q1>>q2;
    ll mv=1e15;
    ll rs=0;
    ll ls=0;
    for (int i=0;i<n;i++){
        cin>>a[i];
        ls+=a[i];
    }
    for (int i=0;i<=n;i++){
        mv=min(mv, ls*l+rs*r+cost(n-i, i, q1, q2));
        ls-=a[n-i-1];
        rs+=a[n-i-1];
    }
    cout<<mv<<endl;
}