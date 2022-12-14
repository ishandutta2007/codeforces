#include<iostream>
#include<string>
using namespace std;
int n,k,sz,lo,hi;
string s[111],str;
int main()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>s[i];
	cin>>str;
	sz=str.size();
	for (int i=1;i<=n;i++)
	{
		if (s[i].size()<sz) lo++;
		if (s[i].size()<=sz) hi++;
	}
	lo++;
	cout<<lo+((lo-1)/k)*5<<" "<<hi+((hi-1)/k)*5<<endl;
	return 0;
}