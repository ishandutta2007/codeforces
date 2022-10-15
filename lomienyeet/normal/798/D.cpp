#include <bits/stdc++.h>
using namespace std;
const int mxN=1e5+5;
int x[mxN],y[mxN],z[mxN];
bool cmp(int a,int b){return x[a]>x[b];}
signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>x[i];
    for(int i=0;i<n;i++)cin>>y[i];
    for(int i=0;i<n;i++)z[i]=i;
    sort(z,z+n,cmp);
    vector<int> ans;
    ans.push_back(z[0]);
    for(int i=1;i<n;i+=2){
        int x=i;
        if(x+1<n&&y[z[x+1]]>y[z[x]])x++;
        ans.push_back(z[x]);
    }
    cout<<ans.size()<<"\n";
    for(auto i:ans)cout<<i+1<<" ";
}