#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t;
    string s;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n>>s;
        if (n%3!=0) {
            cout<<"NO"<<endl;
            continue;
        }
        k=0;
        for(j=0;j<n;j++) {
            if (s[j]=='M') k++;
        }
        if (k*3!=n) {
            cout<<"NO"<<endl;
            continue;
        }
        k=0;
        for(j=0;j<n;j++) {
            if (s[j]=='M') k--;
            else k++;
            if (k<0) break;
        }
        if (k<0) {
            cout<<"NO"<<endl;
            continue;
        }
        k=0;
        for(j=n-1;j>=0;j--) {
            if (s[j]=='M') k--;
            else k++;
            if (k<0) break;
        }
        if (k<0) {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
    }
    return 0;
}