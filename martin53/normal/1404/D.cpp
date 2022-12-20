#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

vector<int> seen[nmax];

vector<int> outp[2];

vector<int> adj[nmax];

bool been[nmax];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n;
    cin>>n;

    if(n%2==0)
    {
        cout<<"First"<<endl;
        cout.flush();

        for(int i=1;i<=n;i++)cout<<i<<" ";
        for(int i=1;i<=n;i++)cout<<i<<" ";
        cout<<endl;
        cout.flush();
        return 0;
    }

    cout<<"Second"<<endl;
    cout.flush();

    for(int i=1;i<=2*n;i++)
    {
        cin>>inp[i];
        seen[inp[i]].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        adj[i].push_back(n+i);
        adj[n+i].push_back(i);

        adj[seen[i][0]].push_back(seen[i][1]);
        adj[seen[i][1]].push_back(seen[i][0]);
    }

    /*
    for(int i=1;i<=2*n;i++)
    {
        cout<<i<<" -> ";for(auto j:adj[i])cout<<j<<" ";cout<<endl;
    }
    */

    for(int i=1;i<=2*n;i++)
        if(been[i]==0)
        {
            vector<int> path={};

            int j=i;

            while(been[j]==0)
            {
                been[j]=1;
                path.push_back(j);

                int nxt=-1;

                for(auto k:adj[j])
                    if(been[k]==0)nxt=k;

                //cout<<"nxt= "<<nxt<<endl;

                if(nxt==-1)break;

                j=nxt;
            }

            //cout<<"path: ";for(auto k:path)cout<<k<<" ";cout<<endl;

            for(int j=0;j<path.size();j++)
                outp[j%2].push_back(path[j]);
        }

    for(int t=0;t<2;t++)
    {
        long long sum=0;

        for(auto k:outp[t])
            sum+=k;

        if(sum%(2*n)==0)
        {
            for(auto k:outp[t])
            {
                cout<<k<<" ";
            }
            cout.flush();
        }
    }
    return 0;
}