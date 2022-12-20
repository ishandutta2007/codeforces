#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,arr[nmax],need[nmax];
map<int,int> seen;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();

cin>>n;
for(int i=1;i<=n;i++)
{
    cin>>arr[i];
    if(seen.count(arr[i]))i--,n--;
    else seen[arr[i]]=1;
}
sort(arr+1,arr+n+1);
int a,b;
cin>>a>>b;
int ans=0;
while(a!=b)
{
    int red=1;
    int p=0;
    for(int i=1;i<=n;i++)
        if(a-a%arr[i]>=b)
        {
        red=max(red,a%arr[i]);
        p++;
        need[p]=arr[i];
        }

    for(int j=1;j<=p;j++)arr[j]=need[j];
    n=p;

    ans++;
    a=a-red;

}
cout<<ans<<endl;
return 0;
}