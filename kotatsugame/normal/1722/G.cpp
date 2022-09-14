#include<iostream>
#include<vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;cin>>N;
		vector<int>ans(N);
		if(N%4==0)
		{
			for(int i=0;i<N;i++)ans[i]=i;
		}
		else if(N%4==1)
		{
			ans[0]=0b0001;
			ans[1]=0b0011;
			ans[2]=0b0110;
			ans[3]=0b1100;
			ans[4]=0b1000;
			for(int i=5;i<N;i++)ans[i]=0b10000+i-5;
		}
		else if(N%4==2)
		{
			ans[0]=0b00001;
			ans[1]=0b00011;
			ans[2]=0b00110;
			ans[3]=0b01100;
			ans[4]=0b11000;
			ans[5]=0b10000;
			for(int i=6;i<N;i++)ans[i]=0b100000+i-6;
		}
		else
		{
			ans[0]=0b01;
			ans[1]=0b11;
			ans[2]=0b10;
			for(int i=3;i<N;i++)ans[i]=0b100+i-3;
		}
		for(int i=0;i<N;i++)cout<<ans[i]<<(i+1==N?"\n":" ");
	}
}