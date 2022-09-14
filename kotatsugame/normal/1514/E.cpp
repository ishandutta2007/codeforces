#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;
int T,N;
int tb[100][100];
bool ask1(int a,int b)
{
	if(tb[a][b]!=0)return tb[a][b]==1;
	cout<<"1 "<<a<<" "<<b<<endl;
	int k;cin>>k;
	if(k==-1)exit(0);
	tb[a][b]=k==1?1:-1;
	return k==1;
}
bool ask2(int x,vector<int>s)
{
	cout<<"2 "<<x<<" "<<s.size();
	for(int u:s)cout<<" "<<u;
	cout<<endl;
	int k;cin>>k;
	if(k==-1)exit(0);
	return k==1;
}
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)for(int j=0;j<N;j++)tb[i][j]=0;
		vector<int>id(N);
		for(int i=0;i<N;i++)id[i]=i;
		sort(id.begin(),id.end(),[](int a,int b){return ask1(b,a);});
		vector<int>ord(N);
		int R=0,pre=0,sz=0;
		for(int i=0;i<N;i++)
		{
			while(R+1<N)
			{
				vector<int>t;
				for(int j=R+1;j<N;j++)t.push_back(id[j]);
				if(ask2(id[i],t))
				{
					R++;
				}
				else break;
			}
			if(R==i)
			{
				for(int j=pre;j<=i;j++)ord[id[j]]=sz;
				pre=++R;
				sz++;
			}
		}
		cout<<3<<endl;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				cout<<(ord[i]>=ord[j]?'1':'0');
			}
			cout<<endl;
		}
		int k;
		cin>>k;
		if(k==-1)return 0;
	}
}