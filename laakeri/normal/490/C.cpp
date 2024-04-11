#include <iostream>

using namespace std;

int ok[1000001];

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    ll a,b;
    cin>>a>>b;
    ll v=0;
    ll k=1;
    for (int i=s.size()-1;i>=0;i--){
        v+=k*(ll)(s[i]-'0');
        v%=b;
        k*=10ll;
        k%=b;
        if (s[i]!='0'&&v==0ll){
            ok[i]=1;
        }
    }
    v=0;
    for (int i=0;i<s.size()-1;i++){
        v*=10ll;
        v%=a;
        v+=(ll)(s[i]-'0');
        v%=a;
        if (v==0ll&&ok[i+1]){
            cout<<"YES"<<'\n';
            string v1="";
            for (int ii=0;ii<=i;ii++){
                v1+=s[ii];
            }
            string v2="";
            for (int ii=i+1;ii<s.size();ii++){
                v2+=s[ii];
            }
            cout<<v1<<endl;
            cout<<v2<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}