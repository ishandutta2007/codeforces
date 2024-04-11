#include <iostream>

using namespace std;

typedef long long ll;

ll mod=1000000007;

const int N=101010;

const ll lolmo=399999947;
const ll lolk=123091;

ll st[2*N];
ll st2[2*N];

ll ht[N];

ll pow(ll a, ll p, ll md){
    if (p==0) return 1;
    if (p==2) return (a*a)%md;
    if (p%2ll==0) return pow(pow(a, p/2, md), 2, md);
    return (a*pow(a, p-1ll, md))%md;
}

ll geth(int a, int b){
    if (a==0) return ht[b];
    else{
        ll v=ht[b];
        v-=(ht[a-1]*pow(lolk, b-a+1, lolmo))%lolmo;
        v+=lolmo;
        return v%lolmo;
    }
}

int asd[N];

ll sum(int a, int b){
    a+=N;
    b+=N;
    ll s=0;
    while (a<=b){
        if (a%2) s+=st[a++];
        if (!(b%2)) s+=st[b--];
        s%=mod;
        a/=2;
        b/=2;
    }
    return s;
}

void add(int i, ll x){
    for (i+=N;i;i/=2){
        st[i]+=x;
        st[i]%=mod;
    }
}

int main(){
    string s1, s2;
    cin>>s1>>s2;
    ll h1=0;
    ll n=s2.size();
    for (int i=0;i<s2.size();i++){
        h1*=lolk;
        h1+=(ll)(s2[i]-'a'+1);
        h1%=lolmo;
    }
    for (int i=0;i<s1.size();i++){
        if (i) ht[i]=ht[i-1];
        ht[i]*=lolk;
        ht[i]+=(ll)(s1[i]-'a'+1);
        ht[i]%=lolmo;
        if (i>=s2.size()-1){
            if (geth(i-s2.size()+1, i)==h1){
                asd[i]=1;
            }
        }
    }
    ll v=0;
    ll et=0;
    for (int i=0;i<s1.size();i++){
        ll t=0;
        if (asd[i]){
            t+=(i-n+2);
            t+=sum(0, i-n);
        }
        else{
            t+=et;
        }
        t%=mod;
        v+=t;
        v%=mod;
        add(i, v);
        //cout<<t<<" "<<v<<" "<<sum(0, i-n)<<endl;
        et=t;
    }
    cout<<v<<endl;
}