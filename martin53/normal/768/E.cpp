#include<bits/stdc++.h>
using namespace std;
/*
int ans[62];
map< pair<int,long long>, int>mem;
int query(int stones,long long state)
{
if(mem.count({stones,state}))return mem[{stones,state}];
vector<bool> seen(stones+1,0);
    for(int i=1;i<=stones;i++)
        if((state&(1<<i))==0)
        seen[query(stones-i,state+(1<<i))]=1;
int mex=0;
while(seen[mex])mex++;
mem[{stones,state}]=mex;
return mex;
}
*/
int ans[64]={0,1,1,2,2,2,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10};
int main()
{
/*
for(int i=1;i<=60;i++)
{
ans[i]=query(i,0);
cout<<ans[i]<<",";
}
*/
int n,x;
int value=0;
cin>>n;
for(int i=1;i<=n;i++)
{
scanf("%i",&x);
value=value^ans[x];
}
if(value)cout<<"NO"<<endl;
else cout<<"YES"<<endl;
return 0;
}