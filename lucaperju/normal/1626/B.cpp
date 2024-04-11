
#include <bits/stdc++.h>
using namespace std;
char v[200003];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,i,j,n,m,k;
    cin>>t;
    while(t--)
    {
        cin>>v;
        n=strlen(v);
        int ok=0;
        for(i=0;i<n-1;++i)
        {
            int a=v[i]-'0';
            int b=v[i+1]-'0';
            if(a+b>9)
                ok=1;
        }
        if(ok==1)
        {
            for(i=n-1;i>0;--i)
            {
                if(v[i]+v[i-1]-'0'-'0'>9)
                    break;
            }
            int pz=i;
            for(i=0;i<pz-1;++i)
                cout<<v[i];
            cout<<(int)(v[pz]+v[pz-1]-'0'-'0');
            for(i=pz+1;i<n;++i)
                cout<<v[i];
            cout<<'\n';
        }
        else
        {
            for(i=1;i<n;++i)
            {
                if(v[i]!='0')
                    break;
            }
            if(i==n)
            {
                for(i=0;i<n-1;++i)
                    cout<<v[i];
                cout<<'\n';
            }
            else
            {
                int pz=i;
                for(i=0;i<pz-1;++i)
                    cout<<v[i];
                cout<<v[pz]+v[pz-1]-'0'-'0';
                for(i=pz+1;i<n;++i)
                    cout<<v[i];
                cout<<'\n';
            }
        }
    }
    return 0;
}