#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector <ll> m[100001];

int main()
{
    ll maxx=0,i,j,n, M,a,b;
    ll ig[100001]={0};
    ll len[100001]={0};
    cin>>n>>M;
    for (ll i=0;i<M;i++)
    {
        cin>>a>>b;
        a--;
        b--;
        if (a>b) m[a].push_back(b);
        else m[b].push_back(a);
        ig[a]++;
        ig[b]++;
    }
    for (i=0;i<n;i++)
    {
        maxx=0;
        for (j=0;j<m[i].size();j++)
            if (len[m[i][j]]>maxx) maxx=len[m[i][j]];
        len[i]=maxx+1;
    }
    //for (ll i=0;i<n;i++) cout<<len[i]<<endl;
    maxx=0;
    for (ll i=0;i<n;i++) maxx=max(maxx,ig[i]*len[i]);
    cout<<maxx;
    return 0;
}