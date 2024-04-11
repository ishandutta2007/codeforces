#include<bits/stdc++.h>
using namespace std;
int n,cnt;
string s;
int num[33];
bool f;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>s;
		memset(num,0,sizeof(num));
		for (int j=0;j<s.size();j++)
		{
			num[s[j]-'a']++;
		}
		f=0;cnt=0;
		for (int j=0;j<26;j++)
		{
			if (num[j]>1)
			{
				f=1;
				break;
			}
			if (num[j] && !num[j+1]) 
			{
				cnt++;
			} 
		}
		if (cnt>1) f=1; 
		if (!f) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}