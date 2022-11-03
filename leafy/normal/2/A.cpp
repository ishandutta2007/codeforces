#include<bits/stdc++.h>
using namespace std;
int n,m;
map<string,int> mp,mp2;
string stu[1005];int sc[1005];
int main(){
    cin>>n;
    int s;
    for(int i=1;i<=n;i++){
        cin>>stu[i]>>sc[i];
        mp[stu[i]]+=sc[i];
    }
    for(auto i:mp) m=max(m,i.second);
    for(int i=1;i<=n;i++){
        mp2[stu[i]]+=sc[i];
        if(mp[stu[i]]==m&&mp2[stu[i]]>=m) {cout<<stu[i];return 0;}
    }
    return 0;
}