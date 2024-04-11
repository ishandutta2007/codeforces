#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,arr[nmax];
vector<int> moves[nmax];
int value[nmax];
bool ask(int pos)
{
    if(value[pos]!=-1)return value[pos];
    int ans=0;
    for(auto k:moves[pos])
    {
        if(ask(k)==0)
        {
            ans=1;
            value[pos]=1;
            return 1;
        }
    }
    value[pos]=0;
    return 0;
}
int main()
{
scanf("%i",&n);
for(int i=1;i<=n;i++)scanf("%i",&arr[i]);
for(int i=1;i<=n;i++)
{
    for(int j=i+arr[i];j<=n;j=j+arr[i])
        if(arr[i]<arr[j])moves[i].push_back(j);
    for(int j=i-arr[i];j>0;j=j-arr[i])
        if(arr[i]<arr[j])moves[i].push_back(j);
}
memset(value,-1,sizeof(value));
for(int i=1;i<=n;i++)
{
    if(ask(i))printf("A");
    else printf("B");
}
printf("\n");
return 0;
}