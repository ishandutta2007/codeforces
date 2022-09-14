#include<iostream>
#include<vector>
using namespace std;
int N;
//bool ex[1000][1000];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	//for(int N=1;N<=1000;N++)
	//{
	int k=(2*N-1+2)/3;
	vector<pair<int,int> >ans;
	if(k%2==1)
	{
		int lo=(k+1)/2,hi=k/2;
		for(int i=lo-1;i>=0;i--)ans.push_back(make_pair(i,lo-1-i));
		for(int i=hi-1;i>=0;i--)ans.push_back(make_pair(lo+i,lo+hi-1-i));
	}
	else
	{
		int lo=k/2,hi=(k-1)/2;
		for(int i=lo-1;i>=0;i--)ans.push_back(make_pair(i,lo-1-i));
		for(int i=hi-1;i>=0;i--)ans.push_back(make_pair(lo+i,lo+hi-1-i));
		ans.push_back(make_pair(k-1,k-1));
	}
	cout<<k<<"\n";
	for(pair<int,int>p:ans)cout<<p.first+1<<" "<<p.second+1<<"\n";
	/*for(int i=0;i<N;i++)for(int j=0;j<N;j++)ex[i][j]=false;
	for(pair<int,int>p:ans)
	{
		for(int i=0;i<N;i++)ex[i][p.second]=ex[p.first][i]=true;
		for(int i=max(-p.first,-p.second);i<min(N-p.first,N-p.second);i++)ex[p.first+i][p.second+i]=true;
	}
	bool fn=false;
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)if(!ex[i][j])fn=true;
	if(fn)cout<<"ERROR : "<<N<<endl;
	}*/
}