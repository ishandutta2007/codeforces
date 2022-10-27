#include<bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    int n,X;
    cin>>n>>X;
    vector<int>a(X+1);
    for(int x=1,y;x<=n;x++)
    cin>>y,a[y]++;
    for(int x=1;x<X;x++)
    if(a[x]%(x+1)!=0){cout<<"No"<<endl;return 0;}
    else a[x+1]+=a[x]/(x+1);
    cout<<"Yes"<<endl;
}