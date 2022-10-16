#include<bits/stdc++.h>
using namespace std;
int a[200001],t;
main() 
{
    int n;
    cin>>n;
    int m=0;
    for(int x=1;x<=n;x++)
    {
        int y;
        cin>>y;
        m=max(y,m);
        if(t==0)a[t++]=y;
        else if(a[t-1]==y)t--;
        else if(a[t-1]<y)return puts("NO"),0;
        else a[t++]=y;
    }
    if(t==0||(t==1&&a[t-1]==m))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}