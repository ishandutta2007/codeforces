//Author:mxh1999
//
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

typedef pair<int,int> pai;
int n;
map<int,int> M1,M2;

long long cmp(const pai &x,const pai &y,const pai &z)
{
    return (long long)(x.first-z.first)*(y.second-z.second)-(long long)(x.second-z.second)*(y.first-z.first);
}
bool query(map<int,int> &M,int x,int y)
{
    map<int,int>::iterator it=M.lower_bound(x);
    if (it==M.end())    return false;
    if (it->first==x)   return y<=it->second;
    if (it==M.begin())  return false;
    map<int,int>::iterator it2=it--;
    return cmp(make_pair(x,y),*it2,*it)>=0;
}
void insert(map<int,int> &M,int x,int y)
{
    M[x]=y;
    map<int,int>::iterator it=M.upper_bound(x);
    if (it!=M.end())
    for (map<int,int>::iterator i=it++;it!=M.end();i=it++)
        if (cmp(*it,*i,make_pair(x,y))<=0)  M.erase(i);else break;
    it=M.find(x);
    if (it!=M.begin())
    for (map<int,int>::iterator i=--it;i!=M.begin();)
    {
        it=i--;
        if (cmp(*it,*i,make_pair(x,y))<=0)  M.erase(it);else break;
    }
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        bool tmp=query(M1,x,y),tmp2=query(M2,x,-y);
        if (op==1)
        {
            if (!tmp)   insert(M1,x,y);
            if (!tmp2)  insert(M2,x,-y);
        }
        if (op==2)  printf(tmp&&tmp2?"YES\n":"NO\n");
    }
    return 0;
}