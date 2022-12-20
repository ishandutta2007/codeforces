#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
bool good(int x)
{
x++;
return (x&(x-1))==0;
}
void solve(int n)
{
//cout<<"n= "<<n<<endl;
if(n==-1)return;
if(n==0)
{
cout<<0<<" ";
return;
}
assert(n>0);
int x=n;
while(good(x)==0)x++;
//cout<<x<<endl;
//system("pause");
int print=n+1-(x-n);
solve(n-print);
for(int i=n-print+1;i<=n;i++)cout<<x-i<<" ";
}
int a[nmax];
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();
int n;
cin>>n;
cout<<1LL*n*(n+1)<<endl;
/*
for(int i=0;i<=n;i++)a[i]=i;
int ans=0;
do
{
    int now=0;
    for(int i=0;i<=n;i++)now=now+(a[i]^i);
    ans=max(ans,now);
}
while(next_permutation(a,a+n+1));

cout<<ans<<endl;

for(int i=0;i<=n;i++)a[i]=i;
do
{
    int now=0;
    for(int i=0;i<=n;i++)now=now+(a[i]^i);
    if(now==ans)
    {
        for(int j=0;j<=n;j++)cout<<a[j]<<" ";cout<<endl;
    }
}
while(next_permutation(a,a+n+1));
*/
solve(n);
return 0;
}