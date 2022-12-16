#include<bits/stdc++.h>
const int nmax=1e6+42;
using namespace std;
int n,arr[nmax];
map<int,int> seen;
int main()
{
scanf("%i",&n);
for(int i=1;i<=n;i++){scanf("%i",&arr[i]);seen[arr[i]]=0;}
long long sum=0;
for(int i=1;i<=n;i++)
{
    int v=i-seen[arr[i]];
    sum=sum+1LL*v*(v-1)/2;
    seen[arr[i]]=i;
}
for(auto k:seen)
{
    int v=n+1-k.second;
    sum=sum+1LL*v*(v-1)/2;
}
//cout<<sum<<endl;
sum=1LL*n*(n+1)*seen.size()-sum*2-n;
printf("%.18f\n",1.0*sum/n/n);
return 0;
}