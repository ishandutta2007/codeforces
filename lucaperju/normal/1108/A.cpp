#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int v[200005];
char vc[200005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie();cout.tie();
    long long n,k,i,j=0,cnt=0,pzs=1,psj=1,cur=1,pz,t;
    char c;
    cin>>t;
    while(t--)
    {
        long long a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a<=c && b>=d)
            cout<<a<<' '<<c+1<<'\n';
        else
        if(c<=a && d>=b)
            cout<<a+1<<' '<<c<<'\n';
        else
        if(b<=c)
            cout<<a<<' '<<d<<'\n';
        else
        if(d<=a)
            cout<<b<<' '<<c<<'\n';
        else
        {
            if(a!=c)
                cout<<a<<' '<<c<<'\n';
            else
                if(b!=d)
                    cout<<b<<' '<<d<<'\n';
        }
    }
    return 0;
}