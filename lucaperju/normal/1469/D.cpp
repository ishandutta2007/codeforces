#include <bits/stdc++.h>
using namespace std;
long long v[200005];
int ok[200003];
vector<int>a;
vector<int>b;
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,i,j,k,mod,m;
    long long x1,y1,x2,y2;
    cin>>t;
    while(t--)
    {
        a.clear();
        b.clear();
        cin>>n;
        for(i=1;i<=n;++i)
        {
            ok[i]=0;
            v[i]=i;
        }
        long long vlc=n;
        while(vlc>=2)
        {
            ok[vlc]=1;
            if(vlc!=3)
                vlc=sqrt(vlc);
            else
                vlc=2;
        }
        for(i=2;i<=n;++i)
        {
            if(!ok[i])
            {
                a.push_back(i);
                b.push_back(n);
            }
        }
        long long mxc=n;
        if(n!=3)
            vlc=sqrt(n);
        else
            vlc=2;
        while(vlc>1)
        {
            a.push_back(mxc);
            b.push_back(vlc);
            v[mxc]=(v[mxc]-1)/vlc+1;
            if(vlc>v[mxc])
                swap(mxc,vlc);
            if(vlc==2)
            {
                while(v[mxc]>2)
                {
                    a.push_back(mxc);
                    b.push_back(vlc);
                    v[mxc]=(v[mxc]-1)/2+1;
                }
            }
            a.push_back(vlc);
            b.push_back(mxc);
            if(vlc!=3)
                vlc=sqrt(vlc);
            else
                vlc=2;
        }
        cout<<a.size()<<'\n';
        for(i=0;i<a.size();++i)
            cout<<a[i]<<' '<<b[i]<<'\n';
    }
    return 0;
}