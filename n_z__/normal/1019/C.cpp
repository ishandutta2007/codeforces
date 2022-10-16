#include<bits/stdc++.h>
using namespace std;
bool v[1000001];
vector<int>e[1000001];
main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int x=1,y,z;x<=m;x++)
    cin>>y>>z,e[y].push_back(z);
    for(int x=1;x<=n;x++)
    sort(e[x].begin(),e[x].end(),[](int x,int y){return x>y;});
    for(int x=1;x<=n;x++)
    if(!v[x])
    for(int y=0;y<e[x].size()&&e[x][y]>x;y++)
    v[e[x][y]]=1;
    vector<int>ans;
    for(int x=n;x>=1;(!v[x]?ans.push_back(x):void()),x--)
    if(!v[x])
    for(int y=0;y<e[x].size();y++)
    v[e[x][y]]=1;
    cout<<ans.size()<<endl;
    for(int x=0;x<ans.size();x++)
    cout<<ans[ans.size()-1-x]<<' ';
}