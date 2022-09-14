#include<iostream>
#include<algorithm>
using namespace std;
int N;
main()
{
	cin>>N;
	for(int i=0;i<N;i++)
	{
		int A,B,C;cin>>A>>B>>C;
		int ans=0;
		for(int j=0;j<=A;j++)for(int k=0;k<=B;k++)
		{
			if(j<=A&&2*j+k<=B&&2*k<=C)ans=max(ans,(j+k)*3);
		}
		cout<<ans<<endl;
	}
}