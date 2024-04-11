#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

ll mod=1000000007;

ll pow(ll a, ll p){
    if (p==0){
        return 1ll;
    }
    if (p==2){
        return (a*a)%mod;
    }
    if (p%2==0){
        return (pow(pow(a, p/2ll)%mod, 2ll))%mod;
    }
    if (p%2==1){
        return (a*pow(a, p-1ll))%mod;
    }
}

struct lol{
    ll val=0;
    ll s=0;
    int is=0;
};

lol lols[11];
string qs[100001];

int main(){
    string s;
    cin>>s;
    int q;
    cin>>q;
    for (int i=0;i<q;i++){
        cin>>qs[i];
    }
    for (int i=q-1;i>=0;i--){
        int d=qs[i][0]-'0';
        lol t;
        t.val=0;
        t.s=0;
        t.is=1;
        for (int ii=3;ii<qs[i].size();ii++){
            if (lols[qs[i][ii]-'0'].is){
                t.val*=pow(10ll, lols[qs[i][ii]-'0'].s);
                t.val%=mod;
                t.val+=lols[qs[i][ii]-'0'].val;
                t.val%=mod;
                t.s+=lols[qs[i][ii]-'0'].s;
                t.s%=(mod-1ll);
            }
            else{
                t.val*=10ll;
                t.val%=mod;
                t.val+=(ll)(qs[i][ii]-'0');
                t.val%=mod;
                t.s++;
                t.s%=(mod-1ll);
            }
        }
        //cout<<d<<" "<<t.val<<" "<<t.s<<endl;
        lols[d]=t;
        //cout<<t.s<<endl;
    }
    ll val=0;
    for (int i=0;i<s.size();i++){
        if (lols[s[i]-'0'].is){
            //cout<<lols[s[i]-'0'].s<<endl;
            //cout<<pow(10ll, lols[s[i]-'0'].s)<<endl;
            val*=pow(10ll, lols[s[i]-'0'].s);
            val%=mod;
            val+=lols[s[i]-'0'].val;
            val%=mod;
        }
        else{
            val*=10ll;
            val%=mod;
            val+=(ll)(s[i]-'0');
            val%=mod;
        }
    }
    cout<<val<<endl;
}