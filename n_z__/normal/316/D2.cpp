#include<bits/stdc++.h>
#define int long long
using namespace std;
const int p=1000000007;
main()
{
    int n;
    cin>>n;
    int c=0;
    for(int x=1,y;x<=n;x++)
    cin>>y,c+=!(y-1);
    int u=1,v=1,w=1;
    for(int x=2;x<=c;x++)
    w=(v+u*(x-1)%p)%p,u=v,v=w;
    for(int x=c+1;x<=n;x++)
    w=w*x%p;
    cout<<w<<endl;
}