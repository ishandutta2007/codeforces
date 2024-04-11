#include<bits/stdc++.h>
using namespace std;

const int nmax=5e3+42,mod=998244353;
int n,k;

vector<int> adj[nmax];

vector<int> my_mult(vector<int> a,vector<int> b)
{
    vector<int> ret(a.size()+b.size()-1,0);

    //do not cut
    for(int i=0;i<a.size();i++)
        for(int j=0;j<b.size();j++)
            if((i+j)<=k)ret[max(i,j)]=(ret[max(i,j)]+1LL*a[i]*b[j])%mod;

    long long sum=0;
    for(auto w:b)sum=(sum+w)%mod;

    //cut
    for(int i=0;i<a.size();i++)
        ret[i]=(ret[i]+sum*a[i])%mod;

    return ret;
}
vector<int> rec(int node,int parent)
{
    vector<int> ret={1};

    for(auto w:adj[node])
        if(w!=parent)
            ret=my_mult(ret,rec(w,node));

    ret.insert(ret.begin(),0);

    //cout<<node<<" -> ";for(auto w:ret)cout<<w<<" ";cout<<endl;

    return ret;
}
int main()
{
    scanf("%i%i",&n,&k);

    for(int i=1;i<n;i++)
    {
        int u,v;

        scanf("%i%i",&u,&v);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ret=rec(1,0);

    int outp=0;

    for(auto w:ret)
        outp=(outp+w)%mod;

    printf("%i\n",outp);

    return 0;
}