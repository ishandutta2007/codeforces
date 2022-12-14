#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s;
int val[10],suml,sumr,cnt,cha;
int main()
{
	cin>>s;
	for (int i=0;i<3;i++) suml+=(s[i]-'0');
	for (int i=3;i<6;i++) sumr+=(s[i]-'0');
	for (int i=0;i<3;i++)
	{
		if (suml<sumr) val[i]=9-(s[i]-'0');
		else val[i]=s[i]-'0';
	}
	for (int i=3;i<6;i++)
	{
		if (suml>sumr) val[i]=9-(s[i]-'0');
		else val[i]=s[i]-'0';
	}
	sort(val,val+6);
	reverse(val,val+6);
	cha=max(sumr-suml,suml-sumr);
	for (int i=0;i<6 && cha>0;i++)
	{
		cnt++;
		cha-=val[i];
	}
	cout<<cnt<<endl;
	return 0;
}