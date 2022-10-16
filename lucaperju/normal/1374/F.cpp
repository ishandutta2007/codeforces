#include <bits/stdc++.h>
using namespace std;
int v[505];
int fv[505];
struct ura
{
    int a,an,pz;
}v1[505];
bool cmp1 (ura a, ura b)
{
    if(a.a<b.a)
        return true;
    if(a.a>b.a)
        return false;
    return a.pz<b.pz;
}
bool cmp2 (ura a, ura b)
{
    return a.pz<b.pz;
}
vector <int> rz;
void idk (int pz)
{
    int a=v[pz];
    v[pz]=v[pz+2];
    v[pz+2]=v[pz+1];
    v[pz+1]=a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long i,j,n,t,m,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ok=0;
        for(i=1;i<=n;++i)
        {
            cin>>v[i];
            ++fv[v[i]];
            if(fv[v[i]]==2)
                ok=1;
            v1[i].a=v[i];
            v1[i].pz=i;
        }
        int cnt=0;
        for(i=1;i<=n;++i)
        {
            for(j=1;j<i;++j)
                if(v[j]>v[i])
                    ++cnt;
        }
        if(cnt%2==1 && ok==0)
        {
            for(i=1;i<=n;++i)
                fv[v[i]]=0;
            cout<<-1<<'\n';
            continue;
        }
        sort(v1+1,v1+n+1,cmp1);
        for(i=1;i<=n;++i)
            v1[i].an=i;
        for(i=1;i<n;++i)
        {
            if(v1[i].a==v1[i+1].a && cnt%2==1)
            {
                cnt=0;
                swap(v1[i].an,v1[i+1].an);
            }
        }
        sort(v1+1,v1+n+1,cmp2);
        for(i=1;i<=n;++i)
            v[i]=v1[i].an;
        rz.clear();
        for(i=1;i<=n;++i)
        {
            for(j=i;j<=n;++j)
                if(v[j]==i)
                    break;
            int pz=j;
            if(pz==i)
                continue;
            while(pz-2>=i)
            {
                rz.push_back(pz-2);
                idk(pz-2);
                pz-=2;
            }
            if(pz==i+1)
            {
                rz.push_back(i);
                rz.push_back(i);
                idk(i);
                idk(i);
            }
        }
        cout<<rz.size()<<'\n';
        for(i=0;i<rz.size();++i)
            cout<<rz[i]<<' ';
        cout<<'\n';
        for(i=1;i<=n;++i)
            fv[v[i]]=0;
    }
    return 0;
}