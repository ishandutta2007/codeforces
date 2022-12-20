#include<bits/stdc++.h>
using namespace std;

const int nmax=105;

int n;

bool passage(int u,int v)
{
    cout<<1<<" "<<u<<" "<<v<<endl;

    int ret;
    cin>>ret;

    return ret;
}

bool check_any(int from,vector<int> to)
{
    cout<<2<<" "<<from<<" "<<to.size();for(auto w:to)cout<<" "<<w;cout<<endl;

    int ret;
    cin>>ret;

    return ret;
}

vector<int> get_path(int l,int r)
{
    if(l==r)return {l};

    int av=(l+r)/2;

    vector<int> LHS=get_path(l,av);
    vector<int> RHS=get_path(av+1,r);

    int pointer_LHS=0,pointer_RHS=0;

    vector<int> ret={};

    while(pointer_LHS<LHS.size()&&pointer_RHS<RHS.size())
    {
        if(passage(LHS[pointer_LHS],RHS[pointer_RHS]))
        {
            ret.push_back(LHS[pointer_LHS]);
            pointer_LHS++;
        }
        else
        {
            ret.push_back(RHS[pointer_RHS]);
            pointer_RHS++;
        }
    }

    while(pointer_LHS<LHS.size())
    {
        ret.push_back(LHS[pointer_LHS]);
        pointer_LHS++;
    }

    while(pointer_RHS<RHS.size())
    {
        ret.push_back(RHS[pointer_RHS]);
        pointer_RHS++;
    }

    return ret;
}

int go_back[nmax];

void solve()
{
    cin>>n;

    vector<int> path=get_path(0,n-1);

    /*
    cout<<"path: ";for(auto w:path)cout<<w<<" ";cout<<endl;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)cout<<adj[i][j];
        cout<<endl;
    }
    */

    int bck=n;

    for(int i=n-1;i>=0;i--)
    {
        bck=min(bck,i-1);

        while(bck>=0)
        {
            vector<int> me={};

            for(int j=0;j<=bck;j++)
                me.push_back(path[j]);

            if(check_any(path[i],me)==0)break;
            else bck--;
        }

        //cout<<"i= "<<i<<" bck= "<<bck<<endl;

        go_back[path[i]]=bck;
    }

    for(int i=0;i<n;i++)go_back[i]++;

    for(int i=0;i<n;i++)
    {
        for(int j=go_back[path[i]];j<=i;j++)
            go_back[path[i]]=min(go_back[path[i]],go_back[path[j]]);
    }

    //cout<<"bck: ";for(int i=0;i<n;i++)cout<<go_back[i]<<" ";cout<<endl;

    cout<<3<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)cout<<(go_back[i]<=go_back[j]);
        cout<<endl;
    }

    int dumb;
    cin>>dumb;

    if(dumb==-1)exit(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int t;
    cin>>t;

    while(t)
    {
        t--;
        solve();
    }

    return 0;
}