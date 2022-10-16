#include<bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    int a,xx,y;
    cin>>a>>xx>>y;
    int x=abs(xx);
    if(y%a==0||x>=a)cout<<-1<<endl;
    else if(2*x>=a&&(y%(2*a)>=a||y/a==0))cout<<-1<<endl;
    else if(x==0&&y%(2*a)<=a&&y/a!=0)cout<<-1<<endl;
    else if(y%(2*a)>=a)cout<<3*(y/(2*a))+2<<endl;
    else if(y/a==0)cout<<1<<endl;
    else if(xx<0)cout<<3*(y/(2*a))<<endl;
    else cout<<3*(y/(2*a))+1<<endl;
}