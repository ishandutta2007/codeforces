#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int d,s;
int path[505][5005],out[10005]={0};
struct node
{
    int res,sum;
}p[505][5005];
node New(int res,int sum)
{
    node t;
    t.res=res; t.sum=sum;
    return t;
}
queue<node>box;
int main()
{

    cin>>d>>s;
    memset(path,-1,sizeof(path));
    path[0][0]=0;
    box.push(New(0,0));
    int bj=0;
    while(!box.empty())
    {
        node u=box.front(); box.pop();
        //cout<<u.res<<" "<<u.sum<<endl;
        if(u.res==0&&u.sum==s){ bj=1; break; }
        for(int i=0;i<=9;i++)
        {
            node v;
            v.res=(u.res*10+i)%d;
            v.sum=u.sum+i;
            if(v.sum>s||path[v.res][v.sum]!=-1)continue;
            path[v.res][v.sum]=i;
            p[v.res][v.sum]=New(u.res,u.sum);
            box.push(v);
        }
    }
    //cout<<bj<<endl;
    if(!bj){ cout<<-1; return 0; }
    int res=0,sum=s;
    while(1)
    {
        if(res==0&&sum==0)break;
        out[++out[0]]=path[res][sum];
        node t=p[res][sum];
        res=t.res; sum=t.sum;
    }
    for(int i=out[0];i>=1;i--)cout<<out[i];
    return 0;
}