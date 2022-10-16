#include <iostream>
#include <algorithm>
using namespace std;
char rez[303];
int main()
{
    ios_base::sync_with_stdio(false);
    long long n,m,p,k,i,j,ok=0,t;
    int a,b;
    cout<<"a\n";
    cin>>a;
    cout.flush();
    if(a==0)
    {
        return 0;
    }
    if(a==300)
    {
        for(i=1;i<=300;++i)
            cout<<'b';
        cout<<'\n';
        cout.flush();
        return 0;
    }
    for(i=1;i<=a+1;++i)
        cout<<'a';
    cout<<'\n';
    cout.flush();
    cin>>b;
    int cb=b;
    if(b==0)
        return 0;
    if(b==a+1)
    {
        for(i=1;i<=a;++i)
            cout<<'b';
        cout<<'\n';
        cout.flush();
        return 0;
    }
    n=a+1;
    for(i=1;i<n;++i)
    {
        for(j=1;j<=n;++j)
        {
            if(j==i)
                cout<<'b';
            else
                cout<<'a';
        }
        cout<<'\n';
        cout.flush();
        int cur;
        cin>>cur;
        if(cur<b)
            rez[i]='b',--cb;
        else
            rez[i]='a';
    }
    for(i=1;i<n;++i)
        cout<<rez[i];
    if(cb)
        cout<<'b';
    else
        cout<<'a';
    cout<<'\n';
    cout.flush();
}