#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int C[100];
int usd[100];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;
		cin>>N;
		long long S=0;
		for(int i=0;i<N;i++)
		{
			cin>>C[i];
			S+=C[i];
		}
		long long a=1,b=1;
		vector<long long>F;
		while(S>0)
		{
			S-=a;
			F.push_back(a);
			long long c=a+b;
			a=b;
			b=c;
		}
		if(S<0)
		{
			cout<<"NO\n";
			continue;
		}
		for(int i=0;i<N;i++)usd[i]=F.size()+1;
		bool ok=true;
		for(int i=F.size();i--;)
		{
			int mid=-1;
			for(int j=0;j<N;j++)
			{
				if(C[j]<F[i]||usd[j]==i+1)continue;
				if(mid==-1||C[mid]<C[j])mid=j;
			}
			if(mid==-1)
			{
				ok=false;
				break;
			}
			C[mid]-=F[i];
			usd[mid]=i;
		}
		cout<<(ok?"YES\n":"NO\n");
	}
}