#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long ask(long long a,long long b)
{
	cout<<"? "<<a<<" "<<b<<endl;
	long long r;
	cin>>r;
	return r;
}
const int N=9;
long long G[N+1][N+1];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int i=1;i<=N;i++)for(int j=i+1;j<=N;j++)
	{
		long long r=ask(i,j);
		if(r==-1)
		{
			cout<<"! "<<j-1<<endl;
			return 0;
		}
		G[i][j]=G[j][i]=r;
	}
	vector<long long>D;
	for(int i=1;i<=N;i++)for(int j=i+1;j<=N;j++)for(int k=j+1;k<=N;k++)
	{
		long long x=G[i][j],y=G[j][k],z=G[k][i];
		D.push_back(x+y+z);
		if((x+y+z)%2==0)D.push_back((x+y+z)/2);
		D.push_back(x+y-z);
		D.push_back(x+z-y);
		D.push_back(y+z-x);
	}
	for(int i=0;i<D.size();)
	{
		if(D[i]<3||D[i]>(long long)1e18)D.erase(D.begin()+i);
		else i++;
	}
	D.push_back(3);
	sort(D.begin(),D.end());
	D.erase(unique(D.begin(),D.end()),D.end());
	int l=0,r=D.size();
	while(r-l>1)
	{
		int mid=(l+r)/2;
		if(ask(1,D[mid])==-1)r=mid;
		else l=mid;
	}
	cout<<"! "<<D[l]<<endl;
}