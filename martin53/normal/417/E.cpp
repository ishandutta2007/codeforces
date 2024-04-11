#include<bits/stdc++.h>
using namespace std;
const int nmax=1e2+42;
int sz[2];
int output[nmax][2];
bool stop=0;
int now[nmax];
void solve(int pos,long long sum,int index)
{
    if(stop)return;
    if(pos>sz[index])
    {
        /*
        cout<<sum<<endl;
        cout<<"now: ";
        for(int j=1;j<=pos;j++)
            cout<<now[j]<<" ";cout<<endl;
        */
        long long s=sqrt(sum);
        if(s*s!=sum)return;
        stop=1;
        for(int i=1;i<pos;i++)
            output[i][index]=now[i];
        return;
    }
    for(int i=1;i<=10;i++)
    {
        now[pos]=i;
        solve(pos+1,sum+i*i,index);
        if(stop)return;
    }
}
int main()
{
cin>>sz[0]>>sz[1];
solve(1,0,0);
stop=0;
solve(1,0,1);
for(int i=1;i<=sz[0];i++)
{
    for(int j=1;j<=sz[1];j++)cout<<output[i][0]*output[j][1]<<" ";
cout<<endl;
}
return 0;
}