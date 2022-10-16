#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char c;
int main()
{
    ios::sync_with_stdio(false);
    int i,j,n,s=0,k,m,mn=999999999,ok=0,st,dr,t,pz,mxst=0,mxdr=0;
    cin>>n;
    while(n--)
    {
        cin>>c;
        int a,b;
        if(c=='+')
        {
            cin>>a>>b;
            if(b>a)
                swap(a,b);
            mxst=max(mxst,a);
            mxdr=max(mxdr,b);
        }
        else
        {
            cin>>a>>b;
            if(b>a)
                swap(a,b);
            if(a>=mxst && b>=mxdr)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
}