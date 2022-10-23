#include<iostream>
#include<vector>
using namespace std;
vector<int>A,B;
int a,b,c,d;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>a>>b>>c>>d;
		A.clear();B.clear();
		for(int i=1;i*i<=a;i++)if(a%i==0)
		{
			A.push_back(i);
			if(a>i*i)A.push_back(a/i);
		}
		for(int i=1;i*i<=b;i++)if(b%i==0)
		{
			B.push_back(i);
			if(b>i*i)B.push_back(b/i);
		}
		int x=-1,y=-1;
		for(int a1:A)
		{
			for(int b1:B)
			{
				if(a1>c/b1)continue;
				int X=c-c%(a1*b1);
				if(a>=X)continue;
				int a2=a/a1,b2=b/b1;
				if(a2>d/b2)continue;
				int Y=d-d%(a2*b2);
				if(b>=Y)continue;
				x=X,y=Y;
				break;
			}
			if(x!=-1)break;
		}
		cout<<x<<" "<<y<<"\n";
	}
}