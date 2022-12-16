#include<bits/stdc++.h>
using namespace std;
const int nmax=5e2+42,LIM=500+42;
int n,k;
int c[nmax];
bitset<LIM> seen[LIM][LIM];
bitset<LIM> outp;
void dfs(int pos,int special,int total)
{
if(total>k)return;
if(pos==n+1)
{
    if(total==k)outp[special]=1;
    return;
}
if(seen[pos][special][total])return;
seen[pos][special][total]=1;
//ignore the number
dfs(pos+1,special,total);
//take it in special
dfs(pos+1,special+c[pos],total+c[pos]);
//take it but not in special
dfs(pos+1,special,total+c[pos]);
}
int main()
{
cin>>n>>k;
for(int i=1;i<=n;i++)cin>>c[i];

dfs(1,0,0);

cout<<outp.count()<<endl;
for(int i=0;i<=k;i++)
    if(outp[i])cout<<i<<" ";
cout<<endl;
return 0;
}