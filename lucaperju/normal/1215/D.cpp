#include <bits/stdc++.h>
using namespace std;
char a[200005],b[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    long long n,i,j,m,k=0,t,s=0,rz=0,fva=0,fvb=0;
    cin>>n;
    int st=0,a=0,b=0,dr=0;
    for(i=1;i<=n/2;++i)
    {
        char c;
        cin>>c;
        if(c=='?')
            ++a;
        else
            st+=c-'0';
    }
    for(i=1;i<=n/2;++i)
    {
        char c;
        cin>>c;
        if(c=='?')
            ++b;
        else
            dr+=c-'0';
    }
    a/=2;
    b/=2;
    if(st+a*9==dr+b*9)
        cout<<"Bicarp";
    else
        cout<<"Monocarp";
    return 0;
}