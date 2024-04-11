#include<bits/stdc++.h>
using namespace std;
int a[501],b[501];
main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int m;
        cin>>m;
        for(int x=1;x<=m;x++)
        cin>>a[x];
        for(int x=1;x<=m;x++)
        cin>>b[x];
        if(m%2==1&&a[m/2+1]!=b[m/2+1]){puts("no");continue;}
        int q=0;
        for(int x=1;x<=m/2;x++)
        for(int y=1;y<=m;y++)
        if(m%2==0||y!=m/2+1)
        {
            if(a[x]==b[m+1-y]&&a[m+1-x]==b[y]){b[y]=b[m+1-y]=0;q++;break;}
        }
        if(q==m/2)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}