#include<bits/stdc++.h>
using namespace std;

map<int, vector< pair<int,int> > > seen;

long long sum(vector<int> x)
{
    sort(x.begin(),x.end());

    long long ret=0;

    /*
    for(int i=0;i<x.size();i++)
        for(int j=i+1;j<x.size();j++)
            ret+=abs(x[i]-x[j]);
    */
    for(int k=0;k<x.size();k++)
        ret+=1LL*x[k]*(k-(int(x.size())-1-k));

    /*
    for(auto w:x)cout<<w<<" ";
    cout<<" -> "<<ret<<endl;
    */

    return ret;
}
long long eval(vector< pair<int,int> > given)
{
    vector<int> x={};
    vector<int> y={};

    for(auto w:given)
    {
        x.push_back(w.first);
        y.push_back(w.second);
    }

    return sum(x)+sum(y);
}
int main()
{
    int n,m;
    scanf("%i%i",&n,&m);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int c;
            scanf("%i",&c);

            seen[c].push_back({i,j});
        }

    long long outp=0;
    for(auto w:seen)
        outp+=eval(w.second);

    printf("%lld\n",outp);

    return 0;
}