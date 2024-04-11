#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int n,a,b;cin>>n>>a>>b;
    string s;cin>>s;
    vector<long long int> v;
    for(long long int i=0;i<n;i++)
    {
        if(s[i]=='1')
            v.push_back(i);
    }
    long long int answer=0;
    answer+=(n+1)*b;
    answer+=n*a;
    if(v.size()==1)
    {
        answer+=2*a+2*b;
    }
    else if(v.size()!=0)
    {
        for(long long int i=0;i<v.size()-1;i++)
        {
            if(v[i+1]-v[i]==1)
            {
                answer+=b;
            }
            else if(v[i+1]-v[i]==2)
            {
                answer+=(v[i+1]-v[i])*b;
            }
            else
            {
                answer+=min((v[i+1]-v[i])*b,2*a+2*b);    
            }
        }
        answer+=2*a+2*b;
    }
    cout<<answer<<"\n";
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