#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
    cin>>s;
    int ans=0,now=1,nv=0;
    for(auto q:s)
    {
        if(q=='+')ans+=now*nv,now=1,nv=0;
        if(q=='-')ans+=now*nv,now=-1,nv=0;
        nv=nv*10+q-'0';
    }
    cout<<ans+now*nv<<endl;
}