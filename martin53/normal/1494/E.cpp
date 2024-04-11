#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

map< pair<int,int>, char> adj;

int cnt_eq=0,cnt_diff=0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n,q;

    cin>>n>>q;
    for(int i=1;i<=q;i++)
    {
        char type;
        cin>>type;

        if(type=='?')
        {
            int k;
            cin>>k;

            if(cnt_eq||(cnt_diff&&k%2==1))cout<<"YES\n";
            else cout<<"NO\n";
        }
        else if(type=='+')
        {
            int u,v;
            char c;

            cin>>u>>v>>c;

            if(adj[{v,u}]==c)cnt_eq++;
            else if(adj[{v,u}])cnt_diff++;

            adj[{u,v}]=c;
        }
        else
        {
            int u,v;

            cin>>u>>v;

            if(adj[{u,v}]==adj[{v,u}])cnt_eq--;
            else if(adj[{v,u}])cnt_diff--;

            adj[{u,v}]=0;
        }
    }

    return 0;
}