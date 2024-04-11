#include <bits/stdc++.h>
using namespace std;
const long long INF=300000000000000000LL;
vector<int>v[300005];
vector<long long>cst[2][300005];
vector<int>ed[300005];
vector<long long>cst1[300005];
long long cstnod[300005];
bool inq[300005];
long long dst[300005];
int str[21][300005];
struct ura
{
    long long v[2][2];
    ura (long long a=0, long long b=0, long long c=0, long long d=0)
    {
        v[0][0]=a;
        v[0][1]=b;
        v[1][0]=c;
        v[1][1]=d;
    }
};
ura dstr[21][300005];
int tc;
int l[300005],r[300005];
long long d1[300005],d2[300005];
void dfs (int pz, int t)
{
    l[pz]=++tc;
    str[0][pz]=t;
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
        {
            d1[pz]=cst[0][pz][i];
            d2[pz]=cst[1][pz][i];
            continue;
        }
        dfs(v[pz][i],pz);
    }
    r[pz]=++tc;
}
priority_queue<int>q;
ura join (ura a, ura b)
{
    ura ans;
    ans.v[0][0] = min(a.v[0][0] + b.v[0][0], a.v[0][1] + b.v[1][0]);
    ans.v[1][0] = min(a.v[1][0] + b.v[0][0], a.v[1][1] + b.v[1][0]);
    ans.v[0][1] = min(a.v[0][0] + b.v[0][1], a.v[0][1] + b.v[1][1]);
    ans.v[1][1] = min(a.v[1][0] + b.v[0][1], a.v[1][1] + b.v[1][1]);
    return ans;
}
bool estr (int a, int b)
{
    if(l[a]<=l[b] && r[b]<=r[a])
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,j,m,n,s=0;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>cstnod[i];
    for(i=1;i<n;++i)
    {
        long long a,b,c,d;
        cin>>a>>b>>c>>d;
        v[a].push_back(b);
        v[b].push_back(a);
        cst[0][a].push_back(c);
        cst[0][b].push_back(c);
        cst[1][a].push_back(d);
        cst[1][b].push_back(d);
        ed[a].push_back(b);
        ed[b].push_back(a);
        cst1[a].push_back(c+d);
        cst1[b].push_back(c+d);
    }
    for(i=1;i<=n;++i)
    {
        ed[0].push_back(i);
        cst1[0].push_back(cstnod[i]);
    }
    for(i=1;i<=n;++i)
        dst[i]=INF;
    inq[0]=true;
    q.push(0);
    while(!q.empty())
    {
        int nod=q.top();
        q.pop();
        inq[nod]=false;
        for(int i=0;i<ed[nod].size();++i)
        {
            int nn=ed[nod][i];
            if(cst1[nod][i]+dst[nod]<dst[nn])
            {
                dst[nn]=cst1[nod][i]+dst[nod];
                if(!inq[nn])
                {
                    inq[nn]=true;
                    q.push(nn);
                }
            }
        }
    }
    for(i=1;i<=n;++i)
        cstnod[i]=dst[i];
    dfs(1,1);
    for(i=1;i<=n;++i)
    {
        dstr[0][i].v[0][0]=d1[i];
        dstr[0][i].v[1][1]=d2[i];
        dstr[0][i].v[0][1]=min(d1[i]+cstnod[str[0][i]],cstnod[i]+d2[i]);
        dstr[0][i].v[1][0]=min(d2[i]+cstnod[str[0][i]],cstnod[i]+d1[i]);
    }
    for(int k=1;k<=19;++k)
    {
        for(i=1;i<=n;++i)
        {
            str[k][i]=str[k-1][str[k-1][i]];
            dstr[k][i]=join(dstr[k-1][i],dstr[k-1][str[k-1][i]]);
        }
    }
    /// and finally all the preprocessing is done, yay  :)
    int nrq;
    cin>>nrq;
    while(nrq--)
    {
        int a,b,ca,cb;
        cin>>a>>b;
        ++a;
        ++b;
        ca=(a&1);
        cb=(b&1);
        a>>=1;
        b>>=1;
        ura da(0,cstnod[a],cstnod[a],0);
        for(int k=19;k>=0;--k)
        {
            if(!estr(str[k][a],b))
            {
                da=join(da,dstr[k][a]);
                a=str[k][a];
            }
        }
        if(!estr(a,b))
        {
            da=join(da,dstr[0][a]);
            a=str[0][a];
        }
        ura db(0,cstnod[b],cstnod[b],0);
        for(int k=19;k>=0;--k)
        {
            if(!estr(str[k][b],a))
            {
                db=join(db,dstr[k][b]);
                b=str[k][b];
            }
        }
        if(!estr(b,a))
        {
            db=join(db,dstr[0][b]);
            b=str[0][b];
        }
        swap(db.v[0][1],db.v[1][0]);
        da=join(da,db);
        cout<<da.v[ca][cb]<<'\n';
    }
    return 0;
}