#include<bits/stdc++.h>
using namespace std;
const int N=100;
string s;
int main()
{
	cin>>s;
	if(s=="0"||s=="1")
	{
		printf("0\n");
		return 0;
	}
	int len=s.length(),ans=0;
	bool flag=0;
	for(int i=1;i<len;i++) if(s[i]=='1') flag=1;
	if(!flag) len--;
	ans++;
	len--;
	ans+=(len)/2;
	printf("%d\n",ans);
	return 0;
}