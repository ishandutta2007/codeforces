#include<iostream>
#include<vector>
using namespace std;
long long M=1e9+7;
string s;
vector<long>a;
long long pow(long long a,long long b){return b?pow(a*a%M,b/2)*(b%2?a:1)%M:1;}
main()
{
	cin>>s;a.push_back(0);bool flag=true;
	int start=0;while(s[start]=='b')start++;
	for(int i=start;i<s.size();i++)
	{
		if(s[i]=='a')
		{
			if(flag)a.back()++;
			else
			{
				a.push_back(1);
				flag=true;
			}
		}
		else
		{
			if(flag)
			{
				a.push_back(1);
				flag=false;
			}
			else a.back()++;
		}
	}
	if(flag)a.erase(a.end()-1);
	long long ans=0;
	for(int i=0;i<a.size();i+=2)
	{
		(ans+=(pow(2,a[i])-1+M)%M*a[i+1]%M)%=M;
		if(i+2<a.size())a[i+2]+=a[i];
	}
	cout<<ans<<endl;
}