//Author:mxh1999
//
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

#define maxn 1010
int n,m,num;
struct Edge
{
    int u,v;
}   edge[maxn];
string name[maxn],name1[maxn];
int room_tmp[maxn],room[maxn],key[maxn],tmp[maxn];
int room1[maxn],key1[maxn],f1[maxn];
bool open[maxn],open1[maxn];
int f[maxn];

int fa(int t)   {return f[t]==t?t:f[t]=fa(f[t]);}
void Union(int x,int y)
{
    int i=fa(x),j=fa(y);
    if (i>j)    swap(i,j);
    if (i!=j)   f[i]=j;
}
int fa1(int t)  {return f1[t]==t?t:f1[t]=fa1(f1[t]);}
void Union1(int x,int y)
{
    int i=fa1(x),j=fa1(y);
    if (i>j)    swap(i,j);
    if (i!=j)   f1[i]=j;
}
int main()
{
    cin>>n>>m>>num;
    //scanf("%d%d%d",&n,&m,&num);
    for (int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        //scanf("%d%d",&x,&y);
        edge[i].u=x,edge[i].v=y;
    }
    for (int i=1;i<=num;i++)
    {
        cin>>name[i];
        name1[i]=name[i];
        cin>>room_tmp[i];
        int op;
        cin>>op;
        while (op--)
        {
            int q;
            cin>>q;
            key[q]=i;
        }
    }
    sort(name+1,name+num+1);
    for (int i=1;i<=num;i++)
        tmp[i]=lower_bound(name+1,name+num+1,name1[i])-name;
    for (int i=1;i<=num;i++)
        room[tmp[i]]=room_tmp[i];
    for (int i=1;i<=m;i++)
        key[i]=room[tmp[key[i]]];
    for (int i=1;i<=n;i++)  f[i]=i;
    bool bo=true;
    while (bo)
    {
        bo=false;
        for (int i=1;i<=m;i++)
        if (!open[i] && (fa(key[i])==fa(edge[i].u) || fa(key[i])==fa(edge[i].v)))
        {
            open[i]=true;
            Union(edge[i].u,edge[i].v);
            bo=true;
        }
    }
    for (int i=1;i<=num;i++)
    {
        string s;
        cin>>s;
        int man=lower_bound(name+1,name+num+1,s)-name;
        cin>>room1[man];
        int op,q;
        cin>>op;
        while (op--)
        {
            cin>>q;
            key1[q]=room1[man];
        }
    }
    for (int i=1;i<=n;i++)  f1[i]=i;
    bo=true;
    while (bo)
    {
        bo=false;
        for (int i=1;i<=m;i++)
        if (!open1[i] && (fa1(key1[i])==fa1(edge[i].u) || fa1(key1[i])==fa1(edge[i].v)))
        {
            open1[i]=true;
            Union1(edge[i].u,edge[i].v);
            bo=true;
        }
    }
    for (int i=1;i<=n;i++)
    if (fa(i)!=fa1(i))  {printf("NO\n");return 0;}
    for (int i=1;i<=m;i++)
    if (fa(key[i])!=fa1(key1[i]))   {printf("NO\n");return 0;}
    for (int i=1;i<=num;i++)
    if (fa(room[i])!=fa1(room1[i])) {printf("NO\n");return 0;}
    printf("YES\n");
    return 0;
}