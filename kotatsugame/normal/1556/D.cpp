#include<iostream>
#include<algorithm>
using namespace std;
int N,K;
int A[10101];
int OR(int i,int j)
{
	cout<<"or "<<i<<" "<<j<<endl;
	int x;cin>>x;return x;
}
int AND(int i,int j)
{
	cout<<"and "<<i<<" "<<j<<endl;
	int x;cin>>x;return x;
}
main()
{
	cin>>N>>K;
	int aAb=AND(1,2);
	int bAc=AND(2,3);
	int cAa=AND(3,1);
	int aOb=OR(1,2);
	int bOc=OR(2,3);
	int cOa=OR(3,1);
	for(int k=0;k<30;k++)
	{
		for(int t=0;t<8;t++)
		{
			int a=t&1,b=t>>1&1,c=t>>2&1;
			if((a&b)==(aAb>>k&1)
				&&(b&c)==(bAc>>k&1)
				&&(c&a)==(cAa>>k&1)
				&&(a|b)==(aOb>>k&1)
				&&(b|c)==(bOc>>k&1)
				&&(c|a)==(cOa>>k&1))
			{
				A[0]|=a<<k;
				A[1]|=b<<k;
				A[2]|=c<<k;
				break;
			}
		}
	}
	for(int i=3;i<N;i++)
	{
		int a=AND(1,i+1);
		int o=OR(1,i+1);
		A[i]=a|o&~A[0];
	}
	sort(A,A+N);
	cout<<"finish "<<A[K-1]<<endl;
}