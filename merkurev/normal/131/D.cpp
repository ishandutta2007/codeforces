#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
int ind=1;
vector <int> q[3005];
int p[3005],k[3005],d[3005],pos[3005];
int dfs(int v,int pr)
{
    //cout<<v<<" "<<ind<<" "<<pr<<endl;
    int t=ind++;
    p[v]=t;
    for (int i=0;i<q[v].size();i++)
    {
        if (!p[q[v][i]])
        {
            t=min(dfs(q[v][i],v),t);
        }
        else
        {
            if (q[v][i]!=pr)
                t=min(t,p[q[v][i]]);
        }
    }
    //cout<<t<<" "<<p[v]<<endl;
    if (v!=0 && t<p[v])
    {
        //cout<<v<<" "<<pr<<endl;
        k[v]=1;
        k[pr]=1;
    }
    return t;
}
int main(){
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        q[x].push_back(y);
        q[y].push_back(x);
    }
    dfs(1,3004);

    for (int i=1;i<=n;i++)
        if (!k[i]) 
            d[i]=-1;
    int min=0,nmin=0;
    while (nmin!=-1)
    {
        min=-1,nmin=-1;
        for (int i=1;i<=n;i++)
        {
            if (!pos[i] && d[i]!=-1 && (min==-1 || min>d[i]))
            {
                //cout<<"!";
                min=d[i];
                nmin=i;
            }
        }
        if (nmin!=-1)
        {
            pos[nmin]=1;
            for (int i=0;i<q[nmin].size();i++)
            {
                if (d[q[nmin][i]]==-1 || (d[q[nmin][i]]>d[nmin]+1))
                {
                    d[q[nmin][i]]=d[nmin]+1;
                }
            }
        }
    }
    for (int i=1;i<=n;i++)
        cout<<d[i]<<" ";
    return 0;
}