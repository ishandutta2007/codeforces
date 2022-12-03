#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t;
    string s;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n>>k;
        cin>>s;
        l=0;
        if (k*2>=n) l=1;
        else for(j=0;j<k;j++){
            if (s[j]!=s[n-j-1]) l=1;
        }
        if (l) cout<<"NO";
        else cout<<"YES";
        cout<<endl;
    }
    return 0;
}