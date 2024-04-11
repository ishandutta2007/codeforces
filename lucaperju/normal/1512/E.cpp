#include <bits/stdc++.h>
using namespace std;
int rz[505];
int fv[505];
int main()
{
    ios_base::sync_with_stdio(false);
    long long i,t,p,j;
    cin>>t;
    while(t--)
    {
        int n,l,r,s;
        cin>>n>>l>>r>>s;
        int sc=0;
        for(i=1;i<=n;++i)
            fv[i]=rz[i]=0;
        int d=r-l+1;
        if(s<d*(d+1)/2 || s>d*(d+1)/2+d*(n-d))
        {
            cout<<-1<<'\n';
            continue;
        }
        int j=0;
        for(i=l;i<=r;++i)
        {
            rz[i]=++j;
            s-=rz[i];
        }
        rz[r+1]=n+1;
        int pzc=r;
        while(s>0)
        {
            if(rz[pzc]+1!=rz[pzc+1])
            {
                ++rz[pzc];
                --s;
            }
            else
                --pzc;
        }
        rz[r+1]=0;
        for(i=1;i<=n;++i)
            fv[rz[i]]=1;
        j=1;
        for(i=1;i<=n;++i)
        {
            while(fv[j]==1)
                ++j;
            if(rz[i]==0)
                rz[i]=j++;
        }
        for(i=1;i<=n;++i)
            cout<<rz[i]<<' ';
        cout<<'\n';
    }
	return 0;
}