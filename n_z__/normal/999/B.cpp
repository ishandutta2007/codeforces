#include<bits/stdc++.h>
using namespace std;
#define int long long
main() {
    int n;
    string s;
    cin>>n>>s;
    for(int x=1;x<=n;x++)
    if(n%x==0){
        string t=s;
        for(int y=1;y<=x;y++)
        t[x-y+1-1]=s[y-1];
        s=t;
    }
    cout<<s<<endl;
}