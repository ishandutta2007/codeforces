#include <iostream>
using namespace std;
int n,k;
string s;
bool check(string t,bool b)
{
	int mn[]={n,n},mx[]={0,0};
	for (int i=0;i<n;i++)
	{
		mn[t[i]-'0']=min(mn[t[i]-'0'],i);
		mx[t[i]-'0']=max(mx[t[i]-'0'],i);
	}
	if (b)
	return (mx[0]-mn[0]>k || mx[1]-mn[1]>k);
	return (mx[0]-mn[0]<k || mx[1]-mn[1]<k);
}
int main()
{
	cin >> n >> k >> s;
	if (check(s,0))
	{
		printf("tokitsukaze");
		return 0;
	}
	bool ok=1;
	for (int i=0;i<2;i++)
	{
		for (int j=0;j<2;j++)
		{
			string t=s;
			for (int m=0;m<k;m++)
			t[m+i*(n-k)]=j+'0';
			ok&=check(t,0);
		}
	}
	if (ok && !check(s,1))
	printf("quailty");
	else
	printf("once again");
}