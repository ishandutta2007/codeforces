#include<iostream>
#include<vector>
#include<queue>
#include<iomanip>
using namespace std;
const long double EPS=1e-8;
long double ask(const vector<pair<long double,long double> >&G,bool tr)
{
	cout<<"? "<<G.size()<<"\n";
	for(pair<long double,long double>p:G)
	{
		if(!tr)cout<<p.first<<" "<<p.second<<"\n";
		else cout<<p.second<<" "<<p.first<<"\n";
	}
	cout.flush();
	long double r;
	cin>>r;
	return r;
}
long double f(int N,int M,bool tr)
{
	if(N==1)return 0;
	else if(N==2)
	{
		vector<pair<long double,long double> >G;
		G.push_back(make_pair(0,0));
		G.push_back(make_pair(1,0));
		G.push_back(make_pair(1,M));
		G.push_back(make_pair(0,M));
		long double ret=ask(G,tr);
		return 1-ret;
	}
	else
	{
		vector<pair<long double,long double> >G;
		G.push_back(make_pair(0,0));
		G.push_back(make_pair(1,0));
		G.push_back(make_pair(1,M));
		G.push_back(make_pair(0,M));
		long double ret=ask(G,tr);
		if(ret>EPS)return 1-ret;
		G.clear();
		G.push_back(make_pair(0,0));
		for(int i=0;i<M;i++)
		{
			G.push_back(make_pair(N,i));
			G.push_back(make_pair(1,i+1));
		}
		G.push_back(make_pair(0,M));
		ret=ask(G,tr);
		return ((2*N-1)-ret*2*(N-1))/2;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N,M;
	cin>>N>>M;
	cout<<fixed<<setprecision(15);
	long double x=f(N,M,false);
	long double y=f(M,N,true);
	cout<<"! "<<x<<" "<<y<<endl;
}