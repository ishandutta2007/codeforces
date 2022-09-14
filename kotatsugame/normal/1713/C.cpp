#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int P[1<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;cin>>N;
		int mx=N-1;
		int t=0;
		while(t*t<mx)t++;
		while(mx>=0)
		{
			while(t>=1&&(t-1)*(t-1)>=mx)t--;
			int add=t*t-mx;
			for(int i=add;i<=mx;i++)P[i]=t*t-i;
			mx=add-1;
		}
		for(int i=0;i<N;i++)cout<<P[i]<<(i+1==N?"\n":" ");
	}
}