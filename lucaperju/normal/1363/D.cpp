#include <bits/stdc++.h>

using namespace std;
int col[1003];
void query (int st, int dr)
{
    int i;
    cout<<"? "<<dr-st+1<<' ';
    for(i=st;i<=dr;++i)
        cout<<i<<' ';
    cout<<'\n';
    cout.flush();
}
char idk[10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,k,t,i,j,mx,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=1;i<=n;++i)
            col[i]=0;
        for(i=1;i<=k;++i)
        {
            int a;
            cin>>a;
            for(j=1;j<=a;++j)
            {
                int b;
                cin>>b;
                col[b]=i;
            }
        }
        query(1,n);
        cin>>mx;
        int st=1,dr=n;
        while(st<dr)
        {
            int mid=(st+dr)/2;
            query(st,mid);
            int a;
            cin>>a;
            if(a==mx)
                dr=mid;
            else
                st=mid+1;
        }
        int clc=col[st];
        int cnt=0;
        for(i=1;i<=n;++i)
            if(col[i]==clc)
                ++cnt;
        if(clc==0)
        {
            cout<<"! ";
            for(i=1;i<=k;++i)
                cout<<mx<<' ';
            cout<<'\n';
            cout.flush();
            cin>>idk;
            continue;
        }
      /*  if(cnt==n)
        {
            cout<<"! "<<mx<<'\n';
            cout.flush();
            cin>>idk;
            continue;
        }*/
        cout<<"? "<<n-cnt<<' ';
        for(i=1;i<=n;++i)
        {
            if(col[i]!=clc)
            {
                cout<<i<<' ';
            }
        }
        cout<<'\n';
        cout.flush();
        int a;
        cin>>a;
        cout<<"! ";
        for(i=1;i<=k;++i)
        {
            if(i==clc)
                cout<<a<<' ';
            else
                cout<<mx<<' ';
        }
        cout<<'\n';
        cout.flush();
        cin>>idk;
    }
    return 0;
}