#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Maxn=200010;
#define a first
#define b second.first
#define id second.second
pair<int,pair<int,int> >p[200001];
main()
{
	int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        n=n*2-1;
        for(int x=1;x<=n;x++)
        cin>>p[x].a>>p[x].b,p[x].id=x;
        sort(p+1,p+1+n);
        cout<<"YES"<<endl;
        p[n+1].b=-1;
        for(int x=1;x<=n;x+=2)
        if(p[x+1].b>p[x].b)cout<<p[x+1].id<<' ';
        else cout<<p[x].id<<' ';
        cout<<endl;
    }
}