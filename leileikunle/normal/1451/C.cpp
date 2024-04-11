#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; cin>>t;
	while(t--)
	{	
		int c[27]={0},d[27]={0};
		long long int n,k; cin>>n>>k;
		string a,b; cin>>a>>b;
		for(int i=0;i<n;i++)
		{
			c[a[i]-'a']++;
			d[b[i]-'a']++;
		}
		bool empty = false;
		for(int i=0;i<26;i++)
		{
			if(c[i]<d[i] || (c[i] -= d[i]) % k!= 0)
			{
				empty = true;
				break;
			}
			c[i+1] += c[i];
		}
		if(empty)
			cout<<"No"<<endl;
		else cout<<"Yes"<<endl; 
	}
}