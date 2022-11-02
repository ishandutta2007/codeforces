#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, m, q, a, b, X[262666], seg[524299];
char A[262666], c;
main()
{
    ios_base::sync_with_stdio(!cin.tie(NULL));cout.tie(NULL);
    cin>>n>>A;m=1<<n;
    for(i=m-2;i>=0;i--)
    {
        if(A[i]=='0')X[m-1-i]=1;
        if(A[i]=='1')X[m-1-i]=2;
        if(A[i]=='?')X[m-1-i]=3;
    }
    for(i=2*m-1;i>=m;i--)seg[i]=1;
    for(i=m-1;i>=1;i--)seg[i]=(X[i]/2)*seg[i*2]+(X[i]%2)*seg[i*2+1];
    for(cin>>q;q--;)
    {
        cin>>a>>c;a--;
        if(c=='0')X[m-1-a]=1;
        if(c=='1')X[m-1-a]=2;
        if(c=='?')X[m-1-a]=3;
        i=m-1-a;
        while(i>0)
        {
            seg[i]=(X[i]/2)*seg[i*2]+(X[i]%2)*seg[i*2+1];
            i/=2;
        }
        cout<<seg[1]<<"\n";
    }
}