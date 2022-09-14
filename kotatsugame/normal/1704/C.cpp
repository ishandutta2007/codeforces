#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N,M;
int A[1<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N>>M;
		for(int i=0;i<M;i++)
		{
			cin>>A[i];
			A[i]--;
		}
		sort(A,A+M);
		vector<int>B(M);
		for(int i=0;i<M-1;i++)
		{
			int a=A[i],b=A[i+1];
			B[i]=b-a-1;
		}
		{
			B[M-1]=(A[0]+N-A[M-1]-1);
		}
		sort(B.begin(),B.end());
		reverse(B.begin(),B.end());
		int day=0;
		int ans=0;
		for(int b:B)
		{
			if(day*2>=b)continue;
			int rest=b-day*2;
			if(rest<=2)
			{
				day++;
				ans++;
			}
			else
			{
				day+=2;
				ans+=rest-1;
			}
		}
		cout<<N-ans<<"\n";
	}
}