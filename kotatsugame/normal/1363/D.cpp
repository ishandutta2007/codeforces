#include<iostream>
#include<vector>
using namespace std;
int T,N,K;
int ask(int L,int R)
{
	cout<<"? "<<R-L;
	for(int i=L;i<R;i++)cout<<" "<<i;
	cout<<endl;
	int x;cin>>x;
	return x;
}
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>K;
		vector<vector<int> >id(K);
		for(int i=0;i<K;i++)
		{
			int k;cin>>k;
			id[i].resize(k);
			for(int j=0;j<k;j++)cin>>id[i][j];
		}
		int L=1,R=N+1;
		int MX=ask(L,R);
		while(R-L>1)
		{
			int mid=(L+R)/2;
			int X=ask(L,mid);
			if(MX==X)R=mid;
			else L=mid;
		}
		vector<int>ans(K);
		for(int i=0;i<K;i++)
		{
			bool mx=true;
			for(int j:id[i])if(j==L)mx=false;
			if(mx)
			{
				ans[i]=MX;
			}
			else
			{
				vector<int>ng(N+1,0);
				for(int j:id[i])ng[j]=1;
				cout<<"? "<<N-id[i].size();
				for(int j=1;j<=N;j++)
				{
					if(ng[j]==0)cout<<" "<<j;
				}
				cout<<endl;
				cin>>ans[i];
			}
		}
		cout<<"!";
		for(int i=0;i<K;i++)cout<<" "<<ans[i];
		cout<<endl;
		string s;cin>>s;
	}
}