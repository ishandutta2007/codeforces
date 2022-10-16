#include<bits/stdc++.h>
using namespace std;
bool b[40000];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int x=1;x<=k;x++)
    {
        int y;
        cin>>y;
        int o,p;
        if(y==2)cin>>o,b[o]=true;
        else cin>>o>>p,b[o]=b[p]=true;
    }
    int ans1=0;
    for(int x=1;x<n;x++)
    if(b[x]==false)ans1++;
    int ans2=ans1;
    for(int x=1;x<n;x++)
    if(b[x]==false&&b[x+1]==false&&x+1<n)ans2--,x++;
    cout<<ans2<<' '<<ans1<<endl;
}