#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t;
    string s;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>s;
        l=s.length();
        j=0;
        k=-1;
        while ((j<l-1)&&(k==-1)) {
            if ((s[j]=='1')&&(s[j+1]=='1')) k=j;
            j++;
        }
        j=l-2;
        m=-1;
        while ((j>0)&&(m==-1)) {
            if ((s[j]=='0')&&(s[j+1]=='0')) m=j;
            j--;
        }
        if ((k!=-1)&&(m!=-1)&&(k<m)) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}