#include<iostream>
using namespace std;
int N;
int A[2<<17];
int B[2<<17];
bool usd[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		int all=0;
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
			all|=A[i];
			usd[i]=false;
		}
		int i=0;
		int now=0;
		while(now<all)
		{
			int mj=-1;
			for(int j=0;j<N;j++)if(!usd[j])
			{
				if(mj==-1||(now|A[j])>(now|A[mj]))mj=j;
			}
			now|=B[i++]=A[mj];
			usd[mj]=true;
		}
		for(int j=0;j<N;j++)if(!usd[j])B[i++]=A[j];
		for(int i=0;i<N;i++)cout<<B[i]<<(i+1==N?"\n":" ");
	}
}