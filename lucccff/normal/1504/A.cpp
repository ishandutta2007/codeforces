#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t;
    string s;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>s;
        k=0;
        l=s.length();
        for(j=0;j<l;j++) if (s[j]!='a') {
            k=1;
            break;
        }
        if (k==0) cout<<"NO\n";
        else {
            cout<<"YES\n";
            m=j;
            if (m*2<l) {
                for(j=0;j<l-m;j++) {
                    cout<<s[j];
                }
                cout<<'a';
                for(j=l-m;j<l;j++) {
                    cout<<s[j];
                }
            }
            else if (m*2>=l) {
                for(j=0;j<l-m-1;j++) {
                    cout<<s[j];
                }
                cout<<'a';
                for(j=l-m-1;j<l;j++) {
                    cout<<s[j];
                }
            }
            cout<<endl;
        }
    }
    return 0;
}