#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t;
    string s;
    getline(cin,s);
    while(s[0]!=0) {
        i=0;
        while((s[i]!='r')) i++;
        if (s[i-1]=='n') cout<<"YES\n";
        else cout<<"NO\n";
        getline(cin,s);
    }
    return 0;
}