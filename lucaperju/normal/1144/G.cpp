#include <bits/stdc++.h>

using namespace std;
int d[200005],st[200005],v[200005],dr[200005],rz[200005];
const int INF=200000000;
int main()
{
    int n,i,j,mxc=-1;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    st[1]=0;
    d[0]=d[1]=INF;
    for(i=2;i<=n;++i)
    {
        if(v[i]<=v[i-1])
            st[i]=st[i-1];
        else
            st[i]=i-1;
    }
    int cr=0;
    for(i=n;i>=1;--i)
    {
        dr[i]=cr;
        if(st[i]!=st[i-1])
            cr=v[i];
    }
    v[0]=-1;
    for(i=2;i<=n;++i)
    {
        if(v[i]>v[i-1])
        {
            int cr=mxc;
            int pz=st[i-1];
            if(v[pz]<v[i] && d[pz]>v[pz+1])
                cr=max(cr,d[pz]);
            if(d[pz+1]>v[pz+2] && pz+2!=i && v[pz+1]<v[i])
                cr=max(cr,d[pz+1]);
            if(cr!=-1)
                d[i]=max(d[i],v[i-1]);
            else
                d[i]=-1;
            d[i]=max(d[i],d[i-1]);
            mxc=-1;
        }
        else if (v[i]<=v[i-1])
        {
            int pz=st[i];
            if(v[pz]<v[i] && d[pz]>v[pz+1] && d[i-1]!=-1)
            {
                if(i-st[i]<=2 || v[i-2]!=v[i-1])
                    d[i]=v[i-1];
                else
                    d[i]=-1;
            }
            else
                d[i]=-1;
        }
        if(v[i]<dr[i] && st[i]!=i-1 && dr[i]!=-1 && v[i]>v[i+1])
            mxc=max(mxc,d[i]);
    }
    for(i=n;i>=1;--i)
    {
        if(d[i]!=-1)
            break;
        if(v[i]<=v[i+1])
            break;
    }
    for(j=n;j>=1;--j)
        rz[j]=1;
    int cur=n,anterior=-1;
    v[n+1]=INF;
    bool solutie(0);
    for(i=n;i>=0;--i)
    {
        if((i==cur || d[i]>v[i+1]) && st[cur]<=i && d[i]!=-1 && v[i]<v[cur+1]&&(i==cur || v[cur]>anterior)) /// ardelean e jmeker
        {
            if(i!=n)
                anterior=-1;
            else if(i!=cur)
                anterior=v[i+1];
            cur=i-1;
            rz[i]=0;
            solutie = 1;
        }
    }
    if (solutie)
        cout << "YES\n";
    else {
        cout << "NO\n";
        return 0;
    }
    for(i=1;i<=n;++i)
        cout<<rz[i]<<' ';
    return 0;
}