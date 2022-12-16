#include<bits/stdc++.h>
using namespace std;
const int nmax=25;
int n,arr[nmax];
int used[nmax];
void rec(int node)
{
    //cout<<node<<endl;
    if(node==0)
    {
        //for(int i=1;i<=n;i++)cout<<arr[i]<<" ";cout<<endl;
        for(int i=1;i<=n;i++)
            if(arr[i])return;
        cout<<"YES"<<endl;
        exit(0);
    }
    for(int p=n;p>node;p--)
        if((arr[p]>=arr[node]+2)||(used[p]&&arr[p]>=arr[node]+1))
        {
            int mem_p=arr[p];
            arr[p]=arr[p]-arr[node]-1;
            used[p]++;
            rec(node-1);
            arr[p]=mem_p;
            used[p]--;
        }
}
int main()
{
cin>>n;
for(int i=1;i<=n;i++)cin>>arr[i];
sort(arr+1,arr+n+1);
for(int i=1;i<=n;i++)
    if(arr[i]==2)
    {
    cout<<"NO"<<endl;
    return 0;
    }
for(int i=1;i<=n;i++)arr[i]--;
rec(n-1);
cout<<"NO"<<endl;
return 0;
}