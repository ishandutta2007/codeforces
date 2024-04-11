#include<iostream>
using namespace std;
int N;
bool ex[1<<20];
int gcd(int a,int b)
{
	while(b)
	{
		int t=a%b;
		a=b;
		b=t;
	}
	return a;
}
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	for(int i=0;i<N;i++)
	{
		int a;cin>>a;
		ex[a]=true;
	}
	int ans=0;
	for(int i=1000000;i>=1;i--)if(!ex[i])
	{
		int fst=-1;
		for(int j=i+i;j<=1000000;j+=i)if(ex[j])
		{
			if(fst==-1)fst=j/i;
			else if(gcd(fst,j/i)==1)
			{
				ex[i]=true;
				break;
			}
		}
		if(ex[i])ans++;
	}
	cout<<ans<<endl;
}