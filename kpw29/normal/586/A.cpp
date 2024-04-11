#include <bits/stdc++.h>
using namespace std;
int t[100];
int a,s,d,f,g,h,j,k,l,o,p,i,u,y,r,e,w,q,z,x,c,v,b,n,m;
int main ()
{
    cin >> n;
    for (i=1;i<=n;i++)
    {
        cin >> t[i];
    }
    for (i=1;i<=n;i++)
    {
        if ((t[i]==1) ||(((t[i+1]!=0) && (t[i-1]!=0) )&&(t[i]==0)))
        b++;
    }
    cout << b;
}