#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
vector<int> adj[nmax];
map<string,int> seen;
map<int,string> inv;
int pos=0;
int n;
void go(int ind)
{
    string now;
    cin>>now;

    int sz=now.size();
    set<string> possible={};
    for(int i=0;i<sz;i++)
        {
        string s="";
        s=s+now[i];
        possible.insert(s);
        }

    for(int i=0;i<sz;i++)
        for(int j=i+1;j<sz;j++)
            {
            string s="";
            s=s+now[i];
            s=s+now[j];
            possible.insert(s);
            }

    for(int i=0;i<sz;i++)
        for(int j=i+1;j<sz;j++)
            for(int k=j+1;k<sz;k++)
                {
                string s="";
                s=s+now[i];
                s=s+now[j];
                s=s+now[k];
                possible.insert(s);
                }


    for(int i=0;i<sz;i++)
        for(int j=i+1;j<sz;j++)
            for(int k=j+1;k<sz;k++)
                for(int l=k+1;l<sz;l++)
                    {
                    string s="";
                    s=s+now[i];
                    s=s+now[j];
                    s=s+now[k];
                    s=s+now[l];
                    possible.insert(s);
                    }

    for(auto k:possible)
    {
        //cout<<ind<<" -> "<<k<<endl;
        if(seen.count(k)==0)
        {
            pos++;
            assert(pos<nmax);
            seen[k]=pos;
            inv[pos]=k;
            //cout<<pos<<" -> "<<k<<endl;
        }
        adj[ind].push_back(seen[k]);
        adj[seen[k]].push_back(ind);
    }
}
int match[nmax];
bool been[nmax];
bool kuhn(int node)
{
    if(been[node])return 0;
    been[node]=1;
    for(auto k:adj[node])
        if(match[k]==0||kuhn(match[k]))
        {
            match[node]=k;
            match[k]=node;
            return 1;
        }
    return 0;
}
int main()
{

freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);

cin>>n;
pos=n;
for(int i=1;i<=n;i++)
    go(i);
/*
for(int i=1;i<=n;i++)
{
        cout<<i<<" -> ";for(auto k:adj[i])cout<<k<<" ";cout<<endl;
}
cout<<"---"<<endl;
*/
for(int i=1;i<=n;i++)
{
    memset(been,0,sizeof(been));
    if(kuhn(i)==0)
    {
        cout<<-1<<endl;
        return 0;
    }
    //cout<<i<<" is ok."<<endl;
}
/*
for(int i=1;i<=n;i++)
    cout<<i<<" -> "<<match[i]<<endl;
*/
for(int i=1;i<=n;i++)
    cout<<inv[match[i]]<<endl;
return 0;
}