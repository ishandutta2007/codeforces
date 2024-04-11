#include<bits/stdc++.h>
using namespace std;
int n,i,moo=0;
int a[500000][7];
void dfs(int t)
{
    if(moo!=2 || t!=1){ moo=2;
    int q,w,e,r;
    q=a[a[t][1]][1];
    w=a[a[t][1]][2];
    e=a[a[t][2]][1];
    r=a[a[t][1]][2];
    if(q==a[t][2] || w==a[t][2])
    {
        if(a[t][1]!=1){
        cout<<a[t][1]<<" ";
        dfs(a[t][1]);}
    }
    else if(a[t][2]!=1){cout<<a[t][2]<<" ";
        dfs(a[t][2]);}}
    else;
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i][1]>>a[i][2];
    }
    if(n==3)
    {
        cout<<"1 2 3";
    }
    else
    {
        cout<<1<< " ";
        dfs(1);
    }
}