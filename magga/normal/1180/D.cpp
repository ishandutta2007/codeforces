#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n,m,count,count1;cin>>n>>m;
    for(int i=1;i<=(n+1)/2;i++)
    {
        if(i!=n-i+1)
        {
            for(int j=1;j<=m;j++)
            {
                cout<<i<<" "<<j<<"\n";
                cout<<n-i+1<<" "<<m-j+1<<"\n";
            }
        }
        else
        {
            
                for(int j=1;j<=(m+1)/2;j++)
                {
                    if(j!=m-j+1)
                    {
                        cout<<i<<" "<<j<<"\n";
                        cout<<n-i+1<<" "<<m-j+1<<"\n";
                    }
                    else
                    {
                        cout<<i<<" "<<j<<"\n";
                    }
                }    
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve(); 
}