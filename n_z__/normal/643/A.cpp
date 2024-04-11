#include<bits/stdc++.h>
using namespace std;
int a[5001],b[5001],c[5001];
int main()
{
    int n;
    cin>>n;
    for(int x=1;x<=n;x++)
    cin>>a[x];
    for(int l=1;l<=n;l++)
    {
        memset(b,0,sizeof(b));
        int nowmax=1;
        for(int r=l;r<=n;r++)
        {
            b[a[r]]++;
            if(b[a[r]]>b[nowmax]||(b[a[r]]==b[nowmax]&&a[r]<nowmax))nowmax=a[r];
            c[nowmax]++;
        }
    }
    for(int x=1;x<=n;x++)
    cout<<c[x]<<' ';
}