#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int lol[300];

ll mod=1e9+7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ma=0;
    for (int i=0;i<s.size();i++){
        lol[s[i]]++;
        ma=max(ma, lol[s[i]]);
    }
    ll f=0;
    for (int i=0;i<300;i++){
        if (lol[i]==ma){
            f++;
        }
    }
    if (f==1){
        cout<<1<<endl;
    }
    else{
        ll v=1;
        for (int i=0;i<s.size();i++){
            v*=f;
            v%=mod;
        }
        cout<<v<<endl;
    }
}