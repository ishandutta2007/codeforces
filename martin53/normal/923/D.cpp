#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
char inp[2][nmax];
pair<int/*A-s*/,int/*B-s*/> sum[2][nmax];

void get_inp(int id)
{
    string now;
    cin>>now;
    int SZ=now.size();
    for(int i=0;i<SZ;i++)
        {
        if(now[i]=='C')now[i]='B';
        inp[id][i+1]=now[i];
        }

    for(int i=1;i<=SZ;i++)
    {
        sum[id][i]=sum[id][i-1];
        if(inp[id][i]=='A')sum[id][i].first++;
        else sum[id][i].second++;
    }
}
pair<int/*A-s*/,int/*B-s*/> find_sum(int id,int l,int r)
{
    pair<int/*A-s*/,int/*B-s*/> ret=sum[id][r];
    ret.first=ret.first-sum[id][l-1].first;
    ret.second=ret.second-sum[id][l-1].second;
    return ret;
}
int a_ending(int id,int l,int r)
{
    int ok=r+1,not_ok=l-1;
    while(ok-not_ok>1)
    {
        int av=(ok+not_ok)/2;
        if(find_sum(id,av,r).second==0)ok=av;
        else not_ok=av;
    }
    return r-ok+1;
}
bool query()
{
    int l,r,lq,rq;

    cin>>l>>r>>lq>>rq;

    int bs=find_sum(0,l,r).second,bt=find_sum(1,lq,rq).second;

    int a_end_s=a_ending(0,l,r),a_end_t=a_ending(1,lq,rq);

    if(bs%2!=bt%2)return 0;
    if(bs>bt)return 0;

    if(bs==bt)return a_end_s>=a_end_t&&a_end_s%3==a_end_t%3;

    if(bs&&bs<bt)return a_end_s>=a_end_t;

    //bs=0, bt!=0
    return a_end_s>a_end_t;
}
int main()
{
get_inp(0);
get_inp(1);

int q;
cin>>q;
for(int i=1;i<=q;i++)
    cout<<query();
return 0;
}