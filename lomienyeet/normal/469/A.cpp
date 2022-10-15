#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    map<int,int> mp;
    int x;
    cin>>x;
    for(int i=0,u;i<x;i++){
        cin>>u;
        mp[u]++;
    }
    int y;
    cin>>y;
    for(int i=0,u;i<y;i++){
        cin>>u;
        mp[u]++;
    }
    if(mp.size()==n)cout<<"I become the guy.";
    else cout<<"Oh, my keyboard!";
}