#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
gp_hash_table<int,int>m[100001];
int f[100001],p[100001];
stack<int>ans;
main()
{
    int n;
    cin>>n;
    int z;
    for(int x=1;x<=n;x++)
    {
        int v,c,l,r;
        cin>>v>>c>>l>>r;
        if(r+c<=100000&&(!l||m[l][r+c])){
            int y=m[l][r+c];
            f[x]=f[y]+v;
            p[x]=y;
            if(!r&&f[x]>f[z])z=x;
            if(f[x]>f[m[l+c][r]])m[l+c][r]=x;
        }
    }
    while(z){if(z>=1&&z<=n)ans.push(z);z=p[z];}
    cout<<ans.size()<<endl;
    while(!ans.empty())cout<<ans.top()<<' ',ans.pop();
}