#include <iostream>

using namespace std;

typedef long long ll;

int v[51];

int main(){
    ll n,m;
    cin>>n>>m;
    if (n==1){
        cout<<1<<endl;
        return 0;
    }
    ll ps=1ll<<(n-1ll);
    ll k=ps/2;
    ll kk=0;
    m--;
    int lr=0;
    int rr=n-1;
    for (int i=1;i<=n;i++){
        if (kk+k<=m){
            v[rr]=i;
            rr--;
            kk+=k;
        }
        else{
            v[lr]=i;
            lr++;
        }
        k/=2;
    }
    for (int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}