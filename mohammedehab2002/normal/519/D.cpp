#include <iostream>
#include <map>
using namespace std;
map<long long,int> m[26];
int arr[26];
char tmp[100005];
int main()
{
	for (int i=0;i<26;i++)
	scanf("%d",&arr[i]);
	getchar();
	gets(tmp);
	string s(tmp);
	long long sum=0,ans=0;
	for (int i=0;i<s.size();i++)
	{
		ans+=m[s[i]-'a'][sum];
		sum+=arr[s[i]-'a'];
		m[s[i]-'a'][sum]++;
	}
	printf("%I64d",ans);
}