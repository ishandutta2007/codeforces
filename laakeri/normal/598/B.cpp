#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    int m;
    cin>>m;
    int n=s.size();
    for (int i=0;i<m;i++){
        int l,r,k;
        cin>>l>>r>>k;
        int le=(r-l+1);
        k%=le;
        l--;
        r--;
        string ns=s;
        for (int j=0;j<le;j++){
            ns[l+j]=s[l+((le+j-k)%le)];
        }
        s=ns;
    }
    cout<<s<<endl;
}