#include <iostream>

using namespace std;

typedef long long ll;

int gcd(int a, int b){
    if (a%b==0) return b;
    return gcd(b, a%b);
}

int lol[1000001][30];

int main(){
    ll n,m;
    cin>>n>>m;
    string s1,s2;
    cin>>s1>>s2;
    ll ss=(ll)s1.size()*n;
    ll mod=gcd(s1.size(), s2.size());
    if (s2.size()<s1.size()){
        swap(s1, s2);
    }
    for (int i=0;i<s1.size();i++){
        lol[i%mod][s1[i]-'a']++;
    }
    ll v=0;
    for (int i=0;i<s2.size();i++){
        for (int ii=0;ii<30;ii++){
            if (s2[i]-'a'!=ii){
                v+=lol[i%mod][ii];
            }
        }
    }
    ll k=(ll)s2.size()*(ll)s1.size();
    k/=mod;
    v*=(ss/k);
    cout<<v<<endl;
}