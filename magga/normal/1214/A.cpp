#include<bits/stdc++.h>
using namespace std;
void help(int index,long long int arr[],vector<long long int>&v)
{
    if(index==-1)
    {
        
    }
    else
    {
        for(long long int i:v)
        {
            v.push_back(i%arr[index]);
        }
        help(index-1,arr,v);
    }
}
void solve()
{
    long long int n,d,e;cin>>n>>d>>e;
    long long int arr[13];
    arr[0]=d;arr[1]=d*2;arr[2]=d*5;arr[3]=d*10;arr[4]=d*20;arr[5]=d*50;arr[6]=d*100;arr[7]=e*5;arr[8]=e*10;
    arr[9]=e*20;arr[10]=e*50;arr[11]=e*100;arr[12]=e*200;
    int n1 = sizeof(arr)/sizeof(arr[0]); 
    sort(arr, arr+n1); 
    long long int answer=n;
    for(long long int i=0;i<=n/d;i++)
    {
        if((n-i*d)%(5*e)<answer)
        {
            answer=(n-i*d)%(5*e);
        }
    }
    cout<<answer<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	solve(); 
}