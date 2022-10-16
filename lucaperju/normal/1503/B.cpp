#include <bits/stdc++.h>
using namespace std;
struct ura
{
    int a,b;
};
vector<ura>v1;
vector<ura>v2;
int main()
{
    ios_base::sync_with_stdio(false);
    int t,n,d,i,j,m;
    cin>>n;
    for(i=1;i<=n;++i)
    for(j=1;j<=n;++j)
    {
        if((i+j)%2==0)
            v1.push_back({i,j});
        else
            v2.push_back({i,j});
    }
    for(i=1;i<=n*n;++i)
    {
        int a;
        cin>>a;
        if(v1.size()==0)
        {
            ura pzc=v2.back();
            if(a==3)
            {
                cout<<2<<' '<<pzc.a<<' '<<pzc.b<<'\n';
                cout.flush();
            }
            else
            {
                cout<<3<<' '<<pzc.a<<' '<<pzc.b<<'\n';
                cout.flush();
            }
            v2.pop_back();
        }
        else if(v2.size()==0)
        {
            ura pzc=v1.back();
            if(a==3)
            {
                cout<<1<<' '<<pzc.a<<' '<<pzc.b<<'\n';
                cout.flush();
            }
            else
            {
                cout<<3<<' '<<pzc.a<<' '<<pzc.b<<'\n';
                cout.flush();
            }
            v1.pop_back();
        }
        else
        {
            if(a==1)
            {
                ura pzc=v2.back();
                cout<<2<<' '<<pzc.a<<' '<<pzc.b<<'\n';
                cout.flush();
                v2.pop_back();
            }
            else
            {
                ura pzc=v1.back();
                cout<<1<<' '<<pzc.a<<' '<<pzc.b<<'\n';
                cout.flush();
                v1.pop_back();
            }
        }
    }
	return 0;
}