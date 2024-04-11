#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> o1,e1,o2,e2;
    for(int i=0,u;i<n;i++){
        cin>>u;
        if(u&1)o1.push_back(u);
        else e1.push_back(u);
    }
    for(int i=0,u;i<m;i++){
        cin>>u;
        if(u&1)o2.push_back(u);
        else e2.push_back(u);
    }
    cout<<min(o1.size(),e2.size())+min(o2.size(),e1.size());
}