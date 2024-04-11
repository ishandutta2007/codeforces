#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,m;
long long head[nmax],power[nmax];
bool can(long long test)
{
    long long pos=1;
    for(int i=1;i<=n;i++)
    {
        if(head[i]-power[pos]>test)return 0;
        if(head[i]>power[pos])
        {
            long long more_1=test-(head[i]-power[pos])*2,pos_1=pos;
            while(pos_1<=m&&head[i]>=power[pos_1])pos_1++;
            while(pos_1<=m&&head[i]+more_1>=power[pos_1])pos_1++;

            long long more_2=(test-(head[i]-power[pos]))/2,pos_2=pos;
            while(pos_2<=m&&head[i]>=power[pos_2])pos_2++;
            while(pos_2<=m&&head[i]+more_2>=power[pos_2])pos_2++;

            pos=max(pos_1,pos_2);
        }
        else
        {
            while(pos<=m&&head[i]+test>=power[pos])pos++;
        }
        if(pos>m)return 1;
    }
    return 0;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();
cin>>n>>m;
for(int i=1;i<=n;i++)cin>>head[i];
for(int i=1;i<=m;i++)cin>>power[i];

long long ok=4e10,not_ok=-1;
while(ok-not_ok>1)
{
    long long av=(ok+not_ok)/2;
    if(can(av))ok=av;
    else not_ok=av;
}
cout<<ok<<endl;
return 0;
}