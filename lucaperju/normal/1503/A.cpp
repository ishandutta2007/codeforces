#include <bits/stdc++.h>
using namespace std;
char v[200003];
char a[200003],b[200003];
int main()
{
    ios_base::sync_with_stdio(false);
    int t,n,d,i,j,m;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>(v+1);
        int cnt=0;
        for(i=1;i<=n;++i)
        {
            v[i]-='0';
            if(v[i]==1)
                ++cnt;
        }
        if(cnt%2)
        {
            cout<<"No\n";
            continue;
        }
        int cntt=0;
        int cnt1=0;
        for(i=1;i<=n;++i)
        {
            if(v[i]==1)
            {
                ++cntt;
                if(cntt<=cnt/2)
                {
                    a[i]='(';
                    b[i]='(';
                }
                else
                {
                    a[i]=')';
                    b[i]=')';
                }
            }
            else
            {
                ++cnt1;
                if(cnt1%2)
                {
                    a[i]='(';
                    b[i]=')';
                }
                else
                {
                    a[i]=')';
                    b[i]='(';
                }
            }
        }
        int ok=1;
        int s=0;
        for(i=1;i<=n;++i)
        {
            if(a[i]=='(')
                ++s;
            else
                --s;
            if(s<0)
                ok=0;
        }
        s=0;
        for(i=1;i<=n;++i)
        {
            if(b[i]=='(')
                ++s;
            else
                --s;
            if(s<0)
                ok=0;
        }
        if(!ok)
            cout<<"NO\n";
        else
        {
            cout<<"YES\n";
            for(i=1;i<=n;++i)
                cout<<a[i];
            cout<<'\n';
            for(i=1;i<=n;++i)
                cout<<b[i];
            cout<<'\n';
          //  cout<<(a+1)<<'\n'<<(b+1)<<'\n';
        }
    }
	return 0;
}