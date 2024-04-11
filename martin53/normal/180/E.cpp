#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42,mmax=1e5+42;
int n,m,k;
int arr[nmax];
queue<int> seen[mmax],emp;
bool can(int le)
{
    for(int i=1;i<=m;i++)seen[i]=emp;
    for(int i=1;i<=n;i++)
    {
        seen[arr[i]].push(i);
        if(seen[arr[i]].size()==le)
        {
            if(i-seen[arr[i]].front()+1-k<=le)
            {
            //cout<<i<<" "<<seen[arr[i]].front()<<" "<<le<<endl;
            return 1;
            }
            seen[arr[i]].pop();
        }
    }
    return 0;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cin>>n>>m>>k;
for(int i=1;i<=n;i++)cin>>arr[i];
int ok=1,not_ok=n+1;
while(not_ok-ok>1)
{
    int av=(ok+not_ok)/2;
    if(can(av))ok=av;
    else not_ok=av;
}
cout<<ok<<endl;
return 0;
}