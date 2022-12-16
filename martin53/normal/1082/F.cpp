#include<bits/stdc++.h>
using namespace std;
const int nmax=5e2+42,SZ=11;

pair<string,int> inp[nmax];

int n,k;

int common[nmax][nmax];

array<int,SZ> my_merge(array<int,SZ> a,array<int,SZ> b)
{
    array<int,SZ> ret;

    for(int i=0;i<SZ;i++)ret[i]=1e7;

    for(int p=0;p<SZ;p++)
        for(int q=0;p+q<SZ;q++)
            ret[p+q]=min(ret[p+q],a[p]+b[q]);

    return ret;
}

array<int,SZ> zero,MX;

unordered_map<int, array<int,11> > mem;

array<int,SZ> rec(int l,int r,int taken)
{
    if(l>r)return zero;

    if(l==r)
    {
        array<int,SZ> ret;
        for(int j=0;j<SZ;j++)
            if(j==0)ret[j]=(inp[l].first.size()-taken)*inp[l].second;
            else ret[j]=0;

        return ret;
    }

    int hsh=taken+501*(l+501*r);

    if(mem.count(hsh))return mem[hsh];

    array<int,SZ> ret;
    for(int j=0;j<SZ;j++)ret[j]=1e7;

    //do nothing
    for(int av=l;av<r;av++)
    {
        array<int,SZ> help=my_merge(rec(l,av,taken),rec(av+1,r,taken));

        for(int j=0;j<=k;j++)
            ret[j]=min(ret[j],help[j]);
    }

    //take as a button
    for(int lq=l;lq<=r;lq++)
        for(int rq=lq;rq<=r&&common[lq][rq]>taken;rq++)
        {
            array<int,SZ> cur=my_merge(rec(l,lq-1,taken),rec(rq+1,r,taken));
            cur=my_merge(rec(lq,rq,common[lq][rq]),cur);

            for(int p=1;p<=k;p++)
                ret[p]=min(ret[p],cur[p-1]);
        }

    //cout<<l<<" "<<r<<" "<<taken<<" -> ";for(auto w:ret)cout<<w<<" ";cout<<endl;

    mem[hsh]=ret;
    return ret;
}
int main()
{
    cin>>n>>k;

    for(int i=0;i<=k;i++)MX[i]=1e7;

    for(int i=1;i<=n;i++)
    {
        cin>>inp[i].first>>inp[i].second;

        bool taken=0;
        for(int j=1;j<i;j++)
            if(inp[i].first==inp[j].first)
            {
                inp[j].second+=inp[i].second;
                taken=1;
                break;
            }

        if(taken)
        {
            i--;
            n--;
        }
    }
    sort(inp+1,inp+n+1);

    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
        {
            int pos=0;

            while(pos<inp[i].first.size()&&pos<inp[j].first.size()&&inp[i].first[pos]==inp[j].first[pos])pos++;

            common[i][j]=pos;
        }

    array<int,SZ> cur=rec(1,n,0);

    int outp=1e9;

    for(int i=0;i<=k;i++)
        outp=min(outp,cur[i]);

    printf("%i\n",outp);
    return 0;
}