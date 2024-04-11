#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[10001];
//const int ans[]={0,1,6,4,2,3,5,4};
main()
{
    int n,k;
    cin>>n>>k;
    cout<<"and 2 3"<<endl,cout<<"or 2 3"<<endl;
    for(int x=2;x<=n;x++)
    cout<<"and 1 "<<x<<endl,cout<<"or 1 "<<x<<endl;
    fflush(stdout);
    int o,p,q,r,s,t;
    /*o=ans[2]&ans[3];p=ans[2]|ans[3];q=ans[1]&ans[2];r=ans[1]|ans[2];s=ans[1]&ans[3];t=ans[1]|ans[3];
    cout<<o<<','<<p<<','<<q<<','<<r<<','<<s<<','<<t<<endl;*/
    cin>>o>>p>>q>>r>>s>>t;
    int sum=(o+p+q+r+s+t)/2;
    a[2]=sum-s-t;
    a[3]=sum-q-r;
    a[1]=sum-o-p;
    for(int x=4;x<=n;x++)
    {
        int y,z;
        //y=ans[1]&ans[x];z=ans[1]|ans[x];
        cin>>y>>z;
        a[x]=y+z-a[1];
    }
    /*for(int x=1;x<=n;x++)
    cout<<a[x]<<endl;*/
    sort(a+1,a+1+n);
    cout<<"finish "<<a[k]<<endl;
}
//1642354