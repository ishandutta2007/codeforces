#include <iostream>
#include <vector>
using namespace std;
vector <int> v[300005];
int viz[300005];
int rz;
int dfs (int pz)
{
    int i,j,mx1=0,mx2=0;
    viz[pz]=1;
    for(int i=0;i<v[pz].size();++i)
    {
        int nn=v[pz][i];
        if(!viz[nn])
        {
            int a=dfs(nn);
            if(a>mx1)
                mx2=mx1,mx1=a;
            else if(a>mx2)
                mx2=a;
        }
    }
    int cat=v[pz].size();
    rz=max(rz,mx1+mx2+1+max(0,cat-2));
    return 1+mx1+max(0,cat-2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    long long i,j,k=0,t,s=0,fva=0,fvb=0,nc;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(i=1;i<=n;++i)
        {
            v[i].clear();
            viz[i]=0;
        }
        for(i=1;i<n;++i)
        {
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        rz=0;
        dfs(1);
        cout<<rz<<'\n';
    }
    return 0;
}