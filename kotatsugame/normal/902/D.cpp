#include<iostream>
#include<vector>
using namespace std;
int n;
vector<vector<int> >G,H;
main()
{
	cin>>n;
	vector<int>origin,amari;origin.push_back(1);G.push_back(origin);
	amari.push_back(0);H.push_back(amari);
	for(int i=0;i<n;i++)
	{
		for(int j=1;j>-2;j-=2)
		{
			vector<int>A;bool flag=true;A.push_back(0);
			for(int k=0;k<G[i].size();k++)
			{
				A.push_back(G[i][k]*j);
			}
			for(int k=0;k<H[i].size();k++)
			{
				A[k]+=H[i][k];
				if(A[k]<-1||A[k]>1)
				{
					flag=false;
					break;
				}
			}
			if(flag)
			{
				G.push_back(A);
				H.push_back(G[i]);
				break;
			}
		}
	}
	if(G.size()<n)
	{
		cout<<-1<<endl;
		return 0;
	}
	cout<<G[n].size()-1<<endl;int d=G[n][G[n].size()-1]<0?-1:1;
	for(int i=0;i<G[n].size();i++)
	{
		cout<<(i?" ":"")<<(d*G[n][i]);
	}
	cout<<endl;
	cout<<H[n].size()-1<<endl;d=H[n][H[n].size()-1]<0?-1:1;
	for(int i=0;i<H[n].size();i++)
	{
		cout<<(i?" ":"")<<(d*H[n][i]);
	}
	cout<<endl;
}