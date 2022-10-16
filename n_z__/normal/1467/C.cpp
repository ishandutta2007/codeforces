#include<bits/stdc++.h>
#define int long long
using namespace std;
int n1,n2,n3,m1,m2,m3,s1,s2,s3;
int a[300005],b[300005],c[300005];
main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int ma,mb,mc;
    ma=mb=mc=1000000000;
    int sa,sb,sc;
    sa=sb=sc=0;
    for(int x=1,y;x<=a;x++)cin>>y,ma=min(ma,y),sa+=y;
    for(int x=1,y;x<=b;x++)cin>>y,mb=min(mb,y),sb+=y;
    for(int x=1,y;x<=c;x++)cin>>y,mc=min(mc,y),sc+=y;
	cout<<sa+sb+sc-2*min(min(min(sa,sb),sc),ma+mb+mc-max(ma,max(mb,mc)));
}