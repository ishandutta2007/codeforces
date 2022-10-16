#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int n,q;cin>>n>>q;
    string s;cin>>s;
    long long int arr[3][n] ;
    if(s[0]=='R')
    {
        arr[1][0]=1;arr[2][0]=1;arr[0][0]=0;
    }
    else if(s[0]=='G')
    {
        arr[0][0]=1;arr[2][0]=1;  arr[1][0]=0;  
    }
    else if(s[0]=='B')
    {
        arr[0][0]=1;arr[1][0]=1;    arr[2][0]=0;
    }
    for(long long int i=1;i<n;i++)
    {
         if(i%3==0)
        {
            if(s[i]=='R')
            {
                arr[1][i]=arr[1][i-1]+1;
                arr[2][i]=arr[2][i-1]+1;
                arr[0][i]=arr[0][i-1];
            }
            else if(s[i]=='G')
            {
                arr[0][i]=arr[0][i-1]+1;
                arr[2][i]=arr[2][i-1]+1;
                arr[1][i]=arr[1][i-1];
            }
            else if(s[i]=='B')
            {
                arr[0][i]=arr[0][i-1]+1;
                arr[1][i]=arr[1][i-1]+1;
                arr[2][i]=arr[2][i-1];
            }
        }
        else if(i%3==1)
        {
            if(s[i]=='G')
            {
                arr[1][i]=arr[1][i-1]+1;
                arr[2][i]=arr[2][i-1]+1;
                arr[0][i]=arr[0][i-1];
            }
            else if(s[i]=='B')
            {
               arr[0][i]=arr[0][i-1]+1;
                arr[2][i]=arr[2][i-1]+1;
                arr[1][i]=arr[1][i-1];
            }
            else if(s[i]=='R')
            {
               arr[0][i]=arr[0][i-1]+1;
                arr[1][i]=arr[1][i-1]+1;
                arr[2][i]=arr[2][i-1];
            }
        }
        else if(i%3==2)
        {
            if(s[i]=='B')
            {
                arr[1][i]=arr[1][i-1]+1;
                arr[2][i]=arr[2][i-1]+1;
                arr[0][i]=arr[0][i-1];
            }
            else if(s[i]=='R')
            {
                arr[0][i]=arr[0][i-1]+1;
                arr[2][i]=arr[2][i-1]+1;
                arr[1][i]=arr[1][i-1];
            }
            else if(s[i]=='G')
            {
                arr[0][i]=arr[0][i-1]+1;
                arr[1][i]=arr[1][i-1]+1;arr[2][i]=arr[2][i-1];
            }
        }
    }
    long long int ans =q;
    for(long long int i=1;i<n-q+1;i++)
    {
        if(arr[0][i+q-1]-arr[0][i-1]<ans)
        {
            ans=arr[0][i+q-1]-arr[0][i-1];
        }
        if(arr[1][i+q-1]-arr[1][i-1]<ans)
        {
            ans=arr[1][i+q-1]-arr[1][i-1];
        }
        if(arr[2][i+q-1]-arr[2][i-1]<ans)
        {
            ans=arr[2][i+q-1]-arr[2][i-1];
        }
        //cout<<ans<<endl;
    }
    if(arr[0][q-1]<ans)
    {
        ans=arr[0][q-1];
    }
    if(arr[1][q-1]<ans)
    {
        ans=arr[1][q-1];
    }if(arr[2][q-1]<ans)
    {
        ans=arr[2][q-1];
    }
    cout<<ans<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num;
    cin>>num;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }   
}