// i am just doing this to lower my TLE bot virtual solve speed

#include <bits/stdc++.h>
using namespace std;
#define int long long
void eat(){
    int n,m;
    cin>>n>>m;
    string s[n+1];
    for(int i=1;i<=n;i++){
        cin>>s[i];
        s[i]="_"+s[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            for(int k=n;k>1;k--){
                if(s[k][i]=='.'&&s[k-1][i]=='*')swap(s[k][i],s[k-1][i]);
            }
        }
    }
    for(int i=1;i<=n;i++)s[i].erase(s[i].begin());
    for(int i=1;i<=n;i++)cout<<s[i]<<"\n";
}
signed main(){
    int t=1;
    cin>>t;
    while(t--)eat();
}