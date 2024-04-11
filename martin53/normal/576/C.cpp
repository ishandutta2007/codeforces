#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42,d=1000;
int n;
vector< pair<int/*y*/,int/*index*/> > p[d+5];
bool cmp_up(pair<int/*y*/,int/*index*/>a,pair<int/*y*/,int/*index*/>b)
{
return a.first<b.first;
}
bool cmp_down(pair<int/*y*/,int/*index*/>a,pair<int/*y*/,int/*index*/>b)
{
return a.first>b.first;
}
int main()
{
scanf("%i",&n);
int x,y;
for(int i=1;i<=n;i++)
{
    scanf("%i%i",&x,&y);
    p[x/d].push_back({y,i});
}
for(int i=0;i<d+5;i++)
{
    if(i%2==0)sort(p[i].begin(),p[i].end(),cmp_up);
    else sort(p[i].begin(),p[i].end(),cmp_down);
    for(auto k:p[i])cout<<k.second<<" ";
}
cout<<endl;
return 0;
}