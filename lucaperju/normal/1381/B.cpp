#include <bits/stdc++.h>
using namespace std;
int v[4003];
int st[4003];
int dr[4003];
vector<int> val;
int sumc[4003];
int main()
{
    long long n,m,i,j,x,y,k,t,l,r;
    cin>>t;
    while(t--)
    {
        cin>>n;
        n*=2;
        for(i=1;i<=n;++i)
            cin>>v[i];
        k=0;
        for(i=n;i>=1;--i)
        {
            while(k>0 && v[st[k]]<v[i])
                --k;
            if(k==0)
                dr[i]=n+1;
            else
                dr[i]=st[k];
            st[++k]=i;
        }
        val.clear();
        int pz=1;
        while(pz<=n)
        {
            int pzn=dr[pz];
            val.push_back(pzn-pz);
            pz=pzn;
        }
        for(i=1;i<=n;++i)
            sumc[i]=0;
        for(int vlc=0;vlc<val.size();++vlc)
        {
            for(i=n;i>=1;--i)
                sumc[i+val[vlc]]|=sumc[i];
            sumc[val[vlc]]=1;
        }
        if(sumc[n/2])
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}