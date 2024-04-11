#include<bits/stdc++.h>
using namespace std;
const int nmax=1e2+5;
int n;
int arr[nmax][nmax];
int a[nmax];
queue<int> q;
bool take[nmax];
int main()
{
cin>>n;
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n;j++)
    {
        char c;
        cin>>c;
        arr[i][j]=c-'0';
    }
}
for(int i=1;i<=n;i++)
{
cin>>a[i];
if(a[i]==0)q.push(i);
}

while(q.size())
{
    int now=q.front();
    q.pop();
    take[now]=1;
    for(int j=1;j<=n;j++)
        if(arr[now][j])
        {
            a[j]--;
            if(a[j]==0)q.push(j);
        }
}
int ans=0;
for(int i=1;i<=n;i++)
    ans=ans+take[i];
cout<<ans<<endl;
for(int i=1;i<=n;i++)
    if(take[i])cout<<i<<" ";cout<<endl;
return 0;
}