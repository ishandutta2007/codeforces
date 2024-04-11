#include <bits/stdc++.h>
using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    for(int i=0;i<a.length();i++){
        if(a[i]<b[i]){
            cout<<"-1\n";
            return 0;
        }
    }
    cout<<b<<"\n";
}