#include<bits/stdc++.h>
using namespace std;
vector<int>v[26];
main(){
    int n,q;
    string s;
    cin>>n>>q>>s;
    for(int x=0;x<n;x++)
    v[s[x]-'a'].push_back(x);
    for(int qwq=1;qwq<=q;qwq++)
    {
        int l,r,k;
        cin>>l>>r>>k;
        l--;
        for(int x=26-26*k,c=l;c<r;x+=k*2-1)
        for(int y=lower_bound(v[x].begin(),v[x].end(),l)-v[x].begin();y<v[x].size()&&v[x][y]<r;y++)
        v[x][y]=c++;
    }
    for(int x=0;x<26;x++)
    for(auto y:v[x])s[y]='a'+x;
    cout<<s<<endl;
    
}