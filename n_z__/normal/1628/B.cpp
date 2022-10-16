#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
    	cin>>n;
    	vector<string>s(n+1);
    	for(int x=1;x<=n;x++)
    	cin>>s[x];
    	unordered_set<string>s1,s2;
    	for(int x=1;x<=n;x++)
    	{
    	    auto y=s[x];
    	    reverse(y.begin(),y.end());
    	    if(s[x]==y){cout<<"YES"<<endl;goto nxt;}
    	    if(s1.count(s[x])||s2.count(s[x])||s1.count(s[x].substr(1))){cout<<"YES"<<endl;goto nxt;}
    	    s1.insert(y),s2.insert(y.substr(1));
    	}
    	cout<<"NO"<<endl;
    	nxt:;
    }
}