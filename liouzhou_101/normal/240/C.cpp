#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	int p=1;
	while ((1<<p)<n) ++p;
	cout<<p<<endl;
	for (int i=0;i<p;++i)
	{
		int k=0;
		for (int j=0;j<n;++j)
			if (j&(1<<i)) ++k;
		printf("%d",k);
		for (int j=0;j<n;++j)
			if (j&(1<<i)) printf(" %d",j+1);
		puts("");
	}
	return 0;
}