#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int n;cin>>n;
    long long int n0,n1;n0=0;n1=0;
    string s;cin>>s;
    for(long long int i=0;i<n;i++)
    {
        if(s[i]=='z')
        {
            n0++;
        }
        else if(s[i]=='n')
        {
            n1++;
        }
    }
    for(long long int i=0;i<n1;i++)
    {
        cout<<1<<" ";
    }
    for(long long int i=0;i<n0;i++)
    {
        cout<<0<<" ";
    }
    cout<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num=1;
    //cin>>num;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }   
}