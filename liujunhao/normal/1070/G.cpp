#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,s[105],h[105],a[105]={0},b[105]={0},out[105]={0};
bool visit[105]={0};
bool Check(int x)
{
    memset(visit,0,sizeof(visit));
    for(int i=1;i<=n;i++)b[i]=a[i];
    int tot=0;
    while(tot<m)
    {
        int BJ=0;
        for(int i=1;i<=m;i++)
        {
            if(visit[i])continue;
            int H=h[i],S=s[i],bj=1;
            while(S!=x)
            {
                if(S<x)S++;
                else S--;
                H+=b[S];
                if(H<0){ bj=0; break; }
            }
            if(bj)
            {
                visit[i]=1; BJ=1; tot++;
                S=s[i]; out[tot]=i;
                while(S!=x)
                {
                    if(S<x)S++;
                    else S--;
                    b[S]=0;
                }
                break;
            }
        }
        if(!BJ)return 0;
    }
    return 1;
}
int main() //ugj
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)cin>>s[i]>>h[i];
    for(int i=1;i<=n;i++)cin>>a[i];
    int bj=0,ed;
    for(int i=1;i<=n;i++)if(Check(i)){ bj=1; ed=i; break; }
    if(!bj)cout<<-1;
    else
    {
        cout<<ed<<endl;
        for(int i=1;i<=m;i++)cout<<out[i]<<" ";
    }
    return 0;
}