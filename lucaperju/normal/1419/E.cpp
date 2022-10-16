#include <bits/stdc++.h>
using namespace std;
int prime[55];
vector<int>vp[55];
vector<int>d;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,k,n,q,rz=0,m;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        d.clear();
        j=0;
        for(i=1;i<=50;++i)
            vp[i].clear();
        int cn=n;
        for(i=2;i*i<=n;++i)
        {
            if(n%i==0)
            {
                d.push_back(i);
                if(n/i!=i)
                    d.push_back(n/i);
            }
            if(cn%i==0)
            {
                prime[++j]=i;
                while(cn%i==0)
                    cn/=i;
            }
        }
        d.push_back(n);
        if(cn!=1)
            prime[++j]=cn;
        m=j;
        if(m==1 || d.size()==3)
        {
            for(i=0;i<d.size();++i)
                cout<<d[i]<<' ';
            cout<<'\n';
            if(m==1)
                cout<<"0\n";
            else
                cout<<"1\n";
            continue;
        }
        if(m==2)
        {
            cout<<prime[1]*prime[2]<<' ';
            for(i=0;i<d.size();++i)
                if(d[i]%prime[1]==0 && d[i]!=prime[1]*prime[2] && d[i]!=n)
                    cout<<d[i]<<' ';
            cout<<n<<' ';
            for(i=0;i<d.size();++i)
                if(d[i]%prime[2]==0 && d[i]%prime[1]!=0)
                    cout<<d[i]<<' ';
            cout<<"\n0\n";
            continue;
        }
        for(i=0;i<d.size();++i)
        {
            int dc=d[i];
            if(dc==prime[1]*1LL*prime[m])
                continue;
            for(j=1;j<=m;++j)
                if(dc%prime[j]==0)
                {
                    vp[j].push_back(dc);
                    break;
                }
        }
        cout<<prime[1]*1LL*prime[m]<<' ';
        for(j=1;j<=m;++j)
        {
            int dif;
            if(j<m)
                dif=prime[j]*1LL*prime[j+1];
            else
                dif=0;
            for(i=0;i<vp[j].size();++i)
                if(vp[j][i]!=dif)
                    cout<<vp[j][i]<<' ';
            if(dif)
                cout<<dif<<' ';
        }
        cout<<'\n';
        cout<<0<<'\n';
    }
    return 0;
}