#include<bits/stdc++.h>
using namespace std;
long long int help(string s)
{
    long long int ans,count;count=0;
    for(long long int i=0;i<s.size();i++)
    {
        if(i%3==0 && s[i]!='R')
        {
            count++;
        }
        else if(i%3==1 && s[i]!='G')
        {
            count++;
        }
        else if(i%3==2 && s[i]!='B')
        {
            count++;
        }
    }
    ans=count;count=0;
    for(long long int i=1;i<=s.size();i++)
    {
        if(i%3==0 && s[i-1]!='R')
        {
            count++;
        }
        else if(i%3==1 && s[i-1]!='G')
        {
            count++;
        }
        else if(i%3==2 && s[i-1]!='B')
        {
            count++;
        }
    }
    if(count<ans)
    {
        ans=count;
    }
    count=0;
    for(long long int i=2;i<=s.size()+1;i++)
    {
        if(i%3==0 && s[i-2]!='R')
        {
            count++;
        }
        else if(i%3==1 && s[i-2]!='G')
        {
            count++;
        }
        else if(i%3==2 && s[i-2]!='B')
        {
            count++;
        }
    }
    if(count<ans)
    {
        ans=count;
    }
    return ans;
}
void solve()
{
    long long int n,k,ans;cin>>n>>k;
    string s;cin>>s;
    ans = k;
    for(long long int i=0;i<n-k+1;i++)
    {
        long long int d =help(s.substr(i,k));
        if(d<ans)
        {
            ans=d;
        }
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