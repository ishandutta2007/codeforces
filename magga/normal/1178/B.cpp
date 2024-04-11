#include<bits/stdc++.h>
using namespace std;
void solve()
{
    string s;cin>>s;
    long long int ar[s.size()];
    ar[0]=0;
    vector<long long int>v;
    for(long long int i=1;i<s.size();i++)
    {
        if(s[i-1]=='v' && s[i]=='v')
        {
            ar[i]=ar[i-1]+1;
        }
        else
        {
            ar[i]=ar[i-1];
        }
        if(s[i]=='o')
        {
            v.push_back(i);
        }
    }
    long long int answer=0;
    for(long long int i:v)
    {
        answer+=ar[i]*(ar[s.size()-1]-ar[i]);
    }
    cout<<answer<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num;
    for(long long int i=0;i<1;i++)
    {
       	solve();
    }   
}