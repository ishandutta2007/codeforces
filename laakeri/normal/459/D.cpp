#include <iostream>
#include <map>

using namespace std;

const int N=1010101;

typedef long long ll;

ll st[N*2];

void add (int i, ll x){
    for (i+=N;i;i/=2) st[i]+=x;
}

ll sum (int a, int b){
    a+=N;
    b+=N;
    ll s=0;
    while (a<=b){
        if (a%2) s+=st[a++];
        if (!(b%2)) s+=st[b--];
        a/=2;
        b/=2;
    }
    return s;
}

map<ll, ll> is;
map<ll, ll> is2;

ll t[1000001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++) cin>>t[i];
    for (int i=n-1;i>=0;i--){
        ++is[t[i]];
        add(is[t[i]], 1);
    }
    ll s=0;
    for (int i=0;i<n;i++){
        add(is[t[i]], -1);
        --is[t[i]];
        ++is2[t[i]];
        //cout<<"lol"<<endl;
        //cout<<is2[t[i]]<<endl;
        //cout<<sum(0, is2[t[i]]-1)<<endl;
        s+=sum(0, is2[t[i]]-1);
    }
    cout<<s<<endl;
}