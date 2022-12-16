#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,m,k;
map<int, vector< pair<int,int> > > seen_x,seen_y;
bool cmp(pair<int/*x*/,int/*type*/> a,pair<int/*x*/,int/*type*/> b)
{
    return a.first<b.first;
}
int calc(vector< pair<int,int> > lines,int en)
{
    if(en==0)return 0;
    vector< pair<int/*x*/,int/*type*/> > points={};
    for(auto k:lines)
        {
        points.push_back({k.first,1});
        points.push_back({k.second,-1});
        }
    points.push_back({0,0});
    points.push_back({en,0});
    sort(points.begin(),points.end(),cmp);

    int not_cut=en,open=points[0].second,SZ=points.size();

        for(int i=1;i<SZ;i++)
        {
        if(open)not_cut=not_cut-(points[i].first-points[i-1].first);
        open=open+points[i].second;
        if(points[i].first==en)break;
        }
    /*
    cout<<"calc "<<endl;
    for(auto k:points)cout<<k.first<<" "<<k.second<<endl;
    cout<<"en "<<en<<" not_cut "<<not_cut<<endl;
    */
    return not_cut;
}
void make_cut(int x,int y,int dist)
{
    //cout<<"make cut "<<x<<" "<<y<<" "<<dist<<endl;
    if(x)
    {
        int ok=m,not_ok=-1;
        while(ok-not_ok>1)
        {
            int av=(ok+not_ok)/2;
            if(calc(seen_x[x],av)>=dist)ok=av;
            else not_ok=av;
        }
        cout<<x<<" "<<0<<" "<<x<<" "<<ok<<endl;
        exit(0);
    }
    //y!=0
        int ok=n,not_ok=-1;
        while(ok-not_ok>1)
        {
            int av=(ok+not_ok)/2;
            if(calc(seen_y[y],av)>=dist)ok=av;
            else not_ok=av;
        }
        cout<<0<<" "<<y<<" "<<ok<<" "<<y<<endl;
        exit(0);
}
int main()
{
cin>>n>>m>>k;
int x1,y1,x2,y2;
for(int i=1;i<=k;i++)
{
    cin>>x1>>y1>>x2>>y2;
    if(x1>x2)swap(x1,x2);
    if(y1>y2)swap(y1,y2);
    if(x1==x2)seen_x[x1].push_back({y1,y2});
    else seen_y[y1].push_back({x1,x2});
}

for(int i=1;i<=n-1;i++)
    if(seen_x.count(i)==0)
    {
        seen_x[i].push_back({1e9+1,1e9+2});
        break;
    }
for(int i=1;i<=m-1;i++)
    if(seen_y.count(i)==0)
    {
        seen_y[i].push_back({1e9+1,1e9+2});
        break;
    }


int g=((n-1)%2?m:0)^((m-1)%2?n:0);

//cout<<"x"<<endl;
for(auto k:seen_x)
    {
    int val=calc(k.second,m);
    g=g^m^val;
    //cout<<k.first<<" -> "<<val<<endl;
    }

//cout<<"y"<<endl;
for(auto k:seen_y)
    {
    int val=calc(k.second,n);
    g=g^n^val;
    //cout<<k.first<<" -> "<<val<<endl;
    }


if(g==0)
{
    cout<<"SECOND"<<endl;
    return 0;
}

cout<<"FIRST"<<endl;
for(auto k:seen_x)
    {
    int val=calc(k.second,m);
    //g=g^m^val;
    int aim=g^val;

    //cout<<k.first<<" -> "<<val<<" "<<aim<<endl;

    if(aim>=val)continue;
    else make_cut(k.first,0,val-aim);
    //cout<<k.first<<" -> "<<val<<endl;
    }

for(auto k:seen_y)
    {
    int val=calc(k.second,n);
    //g=g^m^val;
    int aim=g^val;
    if(aim>=val)continue;
    else make_cut(0,k.first,val-aim);
    //cout<<k.first<<" -> "<<val<<endl;
    }
return 0;
}