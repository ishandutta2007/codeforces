#include <bits/stdc++.h>
using namespace std;
int dpmax[100005];
vector <int> v[100005];
void dfsmx (int pz, int t)
{
    int ok=0;
    int cnt=0;
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]!=t)
        {
            if(v[v[pz][i]].size()==1)
                ok=1;
            else
            {
                dfsmx(v[pz][i],pz);
                cnt=cnt+1+dpmax[v[pz][i]];
            }
        }
    }
    cnt+=ok;
    dpmax[pz]=cnt;
}
int dstroot[2];
void dfsmn (int pz, int t, int dst)
{
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]!=t)
        {
            dfsmn(v[pz][i],pz,dst+1);
        }
    }
    if(v[pz].size()==1)
        dstroot[dst%2]++;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,i,j,t;
    cin>>n;
    for(i=1;i<n;++i)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int root;
    for(i=1;i<=n;++i)
        if(v[i].size()>1)
            root=i;
    dfsmx(root,-1);
    dfsmn(root,-1,0);
    if(dstroot[0] && dstroot[1])
        cout<<"3 ";
    else
        cout<<"1 ";
    cout<<dpmax[root];
    return 0;
}