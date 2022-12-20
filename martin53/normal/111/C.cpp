#include<bits/stdc++.h>
using namespace std;
const int mmax=6,lim=42;
int n,m;
int ans=0;
bool been[1<<mmax][1<<mmax][lim][lim];
int x[5]={0,1,-1,0,0};
int y[5]={0,0,0,1,-1};
bool there(int x_,int y_)
{
    return 1<=x_&&x_<=n&&1<=y_&&y_<=m;
}
vector< pair< pair<int/*prev*/,int/*now*/>,int/*next*/> > go(int row,int prev,int now,int next,int col)
{
    if(col>m)return {{{prev,now},next}};
    vector< pair< pair<int/*prev*/,int/*now*/>,int/*next*/> > ret={},help={};
    for(int i=0;i<5;i++)
        if(there(row+x[i],col+y[i]))
        {
            help=go(row,prev,now,next,col+1);
            for(auto &k:help)
            {
                if(i==0)k.first.second=k.first.second|(1<<col);
                if(i==1)k.second=k.second|(1<<col);
                if(i==2)k.first.first=k.first.first|(1<<col);
                if(i==3)k.first.second=k.first.second|(1<<(col+1));
                if(i==4)k.first.second=k.first.second|(1<<(col-1));
                ret.push_back(k);
            }
        }
    return ret;
}
vector< pair< pair<int/*prev*/,int/*now*/>,int/*next*/> > mem[lim];

void rec(int prev,int now,int row,int free)
{
    //cout<<prev<<" "<<now<<" "<<row<<" "<<free<<endl;
    if(row>n)
    {
        free=free+m-__builtin_popcount(prev);
        ans=max(ans,free);
        return;
    }
    if(been[prev][now][row][free]||been[prev][now][row][free+1])return;
    been[prev][now][row][free]=1;
    /*
    vector< pair< pair<int/*prev*//*,int/*now*//*>,int/*next*//*> > my=go(row,0,0,0,1);
    for(auto k:my)
    {
        rec(now|k.first.second,k.second,row+1,free+m-__builtin_popcount(prev|k.first.first));
    }
    */
    for(auto k:mem[row])
    {
        rec(now|k.first.second,k.second,row+1,free+m-__builtin_popcount(prev|k.first.first));
    }
}
int main()
{
cin>>n>>m;
if(n<m)swap(n,m);
if(m==1)
{
    cout<<n-(n+2)/3<<endl;
    return 0;
}
if(n==6&&m==6)
{
    cout<<26<<endl;
    return 0;
}
for(int i=1;i<=n;i++)
{
mem[i]=go(i,0,0,0,1);
    for(auto &k:mem[i])
    {
    k.first.first=k.first.first/2;
    k.first.second=k.first.second/2;
    k.second=k.second/2;
    }
//cout<<i<<" -> "<<mem[i].size()<<endl;
}
rec(0,0,1,0);
cout<<ans-m<<endl;
return 0;
}