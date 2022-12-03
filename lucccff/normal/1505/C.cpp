#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t;
    string s;
    cin>>s;
    l=s.length();
    j=(int)(s[0]-'A');
    if (l>1) k=(int)(s[1]-'A');
    for(i=2;i<l;i++) {
        if ((k+j)%26!=((int)(s[i]-'A'))) {
            cout<<"NO";
            return 0;
        }
        j=k;
        k=(int)(s[i]-'A');
    }
    cout<<"YES";
    return 0;
}