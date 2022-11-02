#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

ll f[100001];

int N=100010;

ll st[202020];

void add (int a, int b, ll x){
    a+=N;
    b+=N;
    while (a<=b){
        if (a%2) st[a++]+=x;
        if (!(b%2)) st[b--]+=x;
        a/=2;
        b/=2;
    }
}

ll sum (int i){
    ll s=f[i];
    for (i+=N;i;i/=2) s+=st[i];
    return s;
}

ll n,m,w;

int test (ll x){
    memset(st, 0, sizeof(st));
    ll u=0;
    for (int i=0;i<n;i++){
        ll asd=sum(i);
        if (asd<x){
            add(i, i+w-1, x-asd);
            u+=x-asd;
        }
        if (u>m){
            return 0;
        }
    }
    return 1;
}

int main(){
    cin>>n>>m>>w;
    for (int i=0;i<n;i++) cin>>f[i];
    ll mi=1;
    ll ma=(ll)1e9+m;
    while (mi<=ma){
        ll m=(mi+ma)/2;
        if (test(m)){
            mi=m+1;
        }
        else{
            ma=m-1;
        }
    }
    cout<<ma<<endl;
}