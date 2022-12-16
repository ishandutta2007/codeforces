#include<bits/stdc++.h>
using namespace std;
const double TL=1.4;
const int nmax=1e5+42;
int n,m;
vector<int> adj[nmax];
int outp[nmax];
bool edge(int a,int b)
{
    for(auto k:adj[a])
        if(k==b)return 1;
    return 0;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
srand(time(0));
int T=clock();
int x,y;
cin>>n>>m;
for(int i=1;i<=m;i++)
{
    cin>>x>>y;
    x--;
    y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
}
while(1.0*(clock()-T)/CLOCKS_PER_SEC<TL)
{
    for(int i=0;i<n;i++)outp[i]=i;
    random_shuffle(outp,outp+n);
    bool bad=0;
    for(int i=0;i<m;i++)
        if(edge(outp[i],outp[(i+1)%n])){bad=1;break;}
    if(bad==0)
    {
        for(int i=0;i<m;i++)
            cout<<outp[i]+1<<" "<<outp[(i+1)%n]+1<<endl;
        return 0;
    }

}
cout<<-1<<endl;
return 0;
}