#include<bits/stdc++.h>
using namespace std;
const int nmax=3e5+42;
int n,q,arr[nmax];
vector<int> adj[nmax],trav[nmax];
void compress()
{
    for(int i=1;i<=n;i++)
    if(adj[i].size())
    {
        sort(adj[i].begin(),adj[i].end());

        //cout<<i<<" -> ";for(auto k:adj[i])cout<<k<<" ";cout<<endl;

        vector<int> now={};
        now.push_back(adj[i][0]);

        int SZ=adj[i].size(),pointer=0;
        for(int j=1;j<SZ;j++)
            if(adj[i][j]!=now[pointer])
            {
                now.push_back(adj[i][j]);
                pointer++;
            }
        adj[i]=now;
        //cout<<i<<" -> ";for(auto k:adj[i])cout<<k<<" ";cout<<endl;
    }

    for(int i=1;i<=n;i++)
        for(auto k:adj[i])
        trav[k].push_back(i);

}
struct query
{
    int x,y;
};
query inp[nmax];
bool output[nmax];

bool intersting_to_left[nmax],intersting_to_right[nmax];

bool been_to_left[nmax],been_to_right[nmax];

vector< vector<int> > seen_right,seen_left;
vector<int> beg_left,beg_right;
int LIM;
void go_right(int node)
{
    if(node>LIM)return;
    if(been_to_right[node])return;
    been_to_right[node]=1;

    for(auto k:adj[node])
        go_right(k);
}
void go_left(int node)
{
    if(node<LIM)return;
    if(been_to_left[node])return;
    been_to_left[node]=1;

    for(auto k:trav[node])
        go_left(k);
}

bool LE[20][nmax],RI[20][nmax];
void dc(int l,int r,vector<int> active)
{
    if(l==r)return;
    int av=(l+r)/2;

    vector<int> active_help={};
    for(auto k:active)
        if(inp[k].y<=av)active_help.push_back(k);

    dc(l,av,active_help);

    active_help={};
    for(auto k:active)
        if(inp[k].x>=av+1)active_help.push_back(k);

    dc(av+1,r,active_help);

    for(int i=l;i<=av;i++)
        for(auto k:adj[i])
        if(av+1<=k&&k<=r)intersting_to_right[k]=1;

    seen_right={};
    beg_right={};
    for(int i=av+1;i<=r;i++)
        if(intersting_to_right[i])
        {
        seen_right.push_back({});
        beg_right.push_back(i);
        LIM=r;
        go_right(i);
            for(int j=av+1;j<=r;j++)
                if(been_to_right[j])
                {
                seen_right[seen_right.size()-1].push_back(j);
                been_to_right[j]=0;
                }
        }

    for(int i=av+1;i<=r;i++)
        intersting_to_right[i]=0;







    for(int i=av+1;i<=r;i++)
        for(auto k:trav[i])
        if(l<=k&&k<=av)intersting_to_left[k]=1;

    seen_left={};
    beg_left={};
    for(int i=l;i<=av;i++)
        if(intersting_to_left[i])
        {
        seen_left.push_back({});
        beg_left.push_back(i);
        LIM=l;
        go_left(i);
            for(int j=l;j<=av;j++)
                if(been_to_left[j])
                {
                seen_left[seen_left.size()-1].push_back(j);
                been_to_left[j]=0;
                }
        }

    for(int i=l;i<=av;i++)
        intersting_to_left[i]=0;

    vector<int> check_left={},check_right={};

    for(int i=0;i<beg_left.size();i++)
    {
        for(auto k:seen_left[i])
            LE[i][k]=1;
    }

    for(int i=0;i<beg_right.size();i++)
    {
        for(auto k:seen_right[i])
            RI[i][k]=1;
    }

    for(auto k:active)
        if(inp[k].x<=av&&inp[k].y>=av+1)
        {
            int x=inp[k].x,y=inp[k].y;

            int SZ=beg_left.size();

            check_left={};

            for(int i=0;i<SZ;i++)
            {
                if(LE[i][x])check_left.push_back(beg_left[i]);
            }





            SZ=beg_right.size();

            check_right={};

            for(int i=0;i<SZ;i++)
            {
                if(RI[i][y])check_right.push_back(beg_right[i]);
            }

            int SZ_l=check_left.size(),SZ_r=check_right.size();
            for(int p=0;p<SZ_l;p++)
                for(int q=0;q<SZ_r;q++)
                    if((arr[check_left[p]]&arr[check_right[q]]))
                    {
                    output[k]=1;
                    p=SZ_l;
                    q=SZ_r;
                    }
        }



    for(int i=0;i<beg_left.size();i++)
    {
        for(auto k:seen_left[i])
            LE[i][k]=0;
    }

    for(int i=0;i<beg_right.size();i++)
    {
        for(auto k:seen_right[i])
            RI[i][k]=0;
    }




}

int main()
{
scanf("%i%i",&n,&q);
for(int i=1;i<=n;i++)scanf("%i",&arr[i]);

for(int i=0;i<20;i++)
{
    vector<int> there={};
    for(int j=1;j<=n;j++)
        if(((1<<i)&arr[j]))there.push_back(j);
    int SZ=there.size();
    for(int j=1;j<SZ;j++)
        adj[there[j-1]].push_back(there[j]);
}

compress();

vector<int> act={};
for(int i=1;i<=q;i++)
{
    scanf("%i%i",&inp[i].x,&inp[i].y);
    act.push_back(i);
}

dc(1,n,act);

for(int i=1;i<=q;i++)
    if(output[i])printf("Shi\n");
    else printf("Fou\n");
return 0;
}