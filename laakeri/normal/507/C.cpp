#include <iostream>

using namespace std;

typedef long long ll;

ll v=0;

ll h,n;

int go(ll l, ll r, ll d, int s){
    if (n<l||n>r){
        v+=(1ll<<(h-d+2))-1ll;
        return 0;
    }
    else if (l==r){
        return 1;
    }
    else{
        v++;
        ll m=(l+r)/2;
        if (s%2==0){
            if (go(l, m, d+1, 1)) return 1;
            if (go(m+1, r, d+1, 0)) return 1;
        }
        else{
            if (go(m+1, r, d+1, 0)) return 1;
            if (go(l, m, d+1, 1)) return 1;
        }
        return 0;
    }
}

int main(){
    cin>>h>>n;
    go(1, (1ll<<h), 1, 0);
    cout<<v<<endl;
}