#include<bits/stdc++.h>
using namespace std;
const int nmax=1e3+42,mx=2e6+42;
int n,inp[nmax],seen[mx];
bool pr[mx];//0 -> prime, 1 -> nor prime
int main()
{
pr[1]=1;
pr[0]=1;

int p=2;
while(p*p<mx)
{
    for(int j=p*p;j<mx;j=j+p)
        pr[j]=1;
    p++;
    while(pr[p])p++;
}

scanf("%i",&n);
for(int i=1;i<=n;i++)
{
    scanf("%i",&inp[i]);
    seen[inp[i]]++;
}

vector< int > output={};
for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
    if(pr[inp[i]+inp[j]]==0)
    {
        output.push_back(inp[i]);
        output.push_back(inp[j]);
        i=n;
        j=n;
    }

for(int i=2;i+1<mx;i++)
    if(pr[1+i]==0&&seen[1]+min(1,seen[i])>output.size())
    {
        output={};
        for(int j=1;j<=seen[1];j++)output.push_back(1);
        for(int j=1;j<=min(1,seen[i]);j++)output.push_back(i);
    }
if(output.size()==0)output.push_back(inp[1]);
printf("%i\n",output.size());
for(auto k:output)printf("%i ",k);
printf("\n");
return 0;
}