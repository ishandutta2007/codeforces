#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,c,a[50],t[50],t1=0,t2=0,c1=0,c2=0;
    cin>>n>>c;
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<n;i++) cin>>t[i];
    for (int i=0;i<n;i++)
    {
        t1+=t[i];
        t2+=t[n-1-i];
        c1+=max(0,a[i]-c*t1);
        c2+=max(0,a[n-1-i]-c*t2);
    }
    cout<<((c1>c2)?"Limak":((c1<c2)?"Radewoosh":"Tie"));
}