#include<bits/stdc++.h>
using namespace std;
int n,a,b,test,cnt;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d%d",&a,&b,&n);
		cnt=0;
		while(a<=n && b<=n)
		{
			if (a<b) a+=b;
			else b+=a;
			cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}