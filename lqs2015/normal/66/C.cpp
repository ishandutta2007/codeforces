#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;
int ans1,ans2,f,F;
map<string,int> m,n;
string s;
int main()
{
	while(cin>>s)
	{
		F=0;
		while(1)
		{
			int x=s.find_last_of('\\');
			s=s.substr(0,x);
			if (x==2) break; 
			f=n[s];
			n[s]++;
			m[s]+=F;
			ans1=max(ans1,m[s]);
			ans2=max(ans2,n[s]);
			if (!f) F++;
		}
	} 
	cout<<ans1<<" "<<ans2<<endl;
	return 0;
}