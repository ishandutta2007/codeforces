// i just learned today that you can #import
// wow!

#import <bits/stdc++.h>
using namespace std;
#define int long long
void eat(){
    string s;
    cin>>s;
    int n=s.length(),ps[n+1]={};
    s="_"+s;
    for(int i=1;i<=n;i++){
        ps[i]=ps[i-1];
        if(s[i]=='['||s[i]==']'){
            if(i&1)ps[i]++;
            else ps[i]--;
        }
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<abs(ps[r]-ps[l-1])<<"\n";
    }
}
signed main(){
    int t;
    cin>>t;
    while(t--)eat();
}