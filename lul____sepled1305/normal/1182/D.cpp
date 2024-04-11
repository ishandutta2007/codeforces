#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
long long dis[200][100010];
long long a,b,i,n,k,l,p,aa,bb,cc,running,mistake,autocount,complete,fuck,hhhh,maxii=-1,minii=1e9,kkkkk,oooo;
long long designate[200000];
long long visit[200000];
vector<pair<int,int>> ppap;
vector<int> path;
void reach(int llll)
{
    //cout<< "                        "<<llll<<"    "<<graph[llll].size()<<"\n";
    autocount++; int iii;
    if(llll!=cc && graph[llll].size()==2&& visit[llll]==0)
    {
        visit[llll]=1;
        for(iii=0;iii<=1;iii++)
        {
            reach(graph[llll][iii]);
        }
    }
    else if (visit[llll]==0 && graph[llll].size()==1)
    {
        //cout<<"HELLLLOOOOO";
        visit[llll]=1;
        pair<int,int> uu;
        uu.first=autocount;
        uu.second=llll;
        ppap.push_back(uu);
    }
    else if (llll==cc && visit[llll]==0)
    {
        visit[cc]=1;
        for(iii=0;iii<graph[cc].size();iii++)
        {
            reach(graph[cc][iii]);
        }
    }
    autocount--;
}
void reset()
{
    int zzz;
    for(zzz=0;zzz<200000;zzz++)
    {
        visit[zzz]=0;
    }
}
void dfs(int j)
{
    int h;
    //cout<<j<<"               This is bug.\n";
    if(visit[j]!=1)
    {
        //cout<<j<<"               This is bug.\n";
        visit[j]=1;
        //autocount++;
        //cout<<autocount;
        dis[running][j]=autocount;
        for(h=0;h<graph[j].size();h++)
        {
            autocount=dis[running][j]+1;
            dfs(graph[j][h]);
        }
    }
}
void path_recdfs(int jjj)
{
    int h;
    if(visit[jjj]!=1 && jjj!=bb && complete==0)
    {
        visit[jjj]=1;
        path.push_back(jjj);
        //cout<<jjj<<"               This is bug.\n";
        for(h=0;h<graph[jjj].size();h++)
        {
            path_recdfs(graph[jjj][h]);
        }
        if(complete==0)
        {
            path.pop_back();
        }
        //cout<<"You're dumb";
        //cout<<"YOu're bumb";
    }
    if(jjj==bb && visit[jjj]==0)
    {
        complete=1;
        visit[jjj]=1;
        path.push_back(bb);
    }
}
void diameter()
{
    int zz,maxi=-1e9;
    dfs(0);
    for(zz=0;zz<n;zz++)
    {
        if(dis[0][zz]>maxi)
        {
            maxi=dis[0][zz];
            aa=zz;
            //cout<<"               "<<dis[0][zz]<<" "<<zz<<"\n";
        }
        //cout<<dis[0][zz];
    }
    running++;
    reset();
    autocount=0;
    dfs(aa);
    zz=0; maxi=-1e9;
    for(zz=0;zz<n;zz++)
    {
        if(dis[1][zz]>maxi)
        {
            maxi=dis[1][zz];
            bb=zz;
        }
    }
    reset();
    autocount=0;
}
void findmidpoint(int z, int x)
{
    running++;
    autocount=0;
    path_recdfs(z);
    //if(n==93784)
    //cout<<path.size();
    //cout<<path[path.size()/2 +1];
    cc=path[path.size()/2];
}
int check(int ll)
{
    int jj,ii;
    for(ii=0;ii<200000;ii++)
    {
        designate[ii]=0;
    }
    mistake=0;
    reset();
    autocount=0;
    running++;
    dfs(ll);
    for(ii=0;ii<n;ii++)
    {
        //cout<<dis[running][ii]<<"\n";
        if(designate[dis[running][ii]]!=0 && designate[dis[running][ii]]!= graph[ii].size())
        {
            mistake++;
        }
        else if(designate[dis[running][ii]]==0)
        {
            designate[dis[running][ii]]= graph[ii].size();
        }
    }
    //cout<<"\n";
    if(mistake==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    cin>>n;
    for(i=0;i<n;i++)
    {
        vector<int> v;
        //v.push_back(0);
        graph.push_back(v);
    }
    for(i=0;i<n-1;i++)
    {
        scanf("%d%d",&a,&b);
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    diameter();
    //if(n==99998) {cout<<"I'm cheating";}
    findmidpoint(aa,bb); reset(); autocount=-1;
    //if(n==99998) {cout<<"I'm cheating";}
    reach(cc);
    //if(n==99998) {cout<<"I'm cheating";}
    for(hhhh=0;hhhh<ppap.size();hhhh++)
    {
        if(maxii<ppap[hhhh].first)
        {
            maxii=ppap[hhhh].first;
            kkkkk=ppap[hhhh].second;
        }
        if(minii>ppap[hhhh].first)
        {
            minii=ppap[hhhh].first;
            oooo=ppap[hhhh].second;
        }
    }
    if(check(aa))
    {
        cout<<aa+1;
    }
    else if(check(bb))
    {
        cout<<bb+1;
    }
    else if(check(cc))
    {
        cout<<cc+1;
    }
    else if(ppap.size()>0)
    {
        if(check(kkkkk))
        {
            cout<<kkkkk+1;
        }
        else if(check(oooo))
        {
            cout<<oooo+1;
        }
        else
        {
            cout<<-1;
        }
    }
    else
    {
        cout<<-1;
    }
    //cout<<aa<<bb<<cc<<ppap[1]<<check(1)<<check(0);
    return 0;
}