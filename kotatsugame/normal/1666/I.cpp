#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int T;
pair<int,int>f(int r1r2,int N,bool fst,int c1c2)
{
	vector<pair<int,int> >rs;
	for(int r1=1;r1<=N;r1++)
	{
		int r2=r1r2-r1;
		if(r1<=r2&&r2<=N)rs.push_back(make_pair(r1,r2));
	}
	if(rs.size()==1)return rs[0];
	for(int d=1;d<=N;d++)
	{
		vector<int>can(rs.size());
		for(int i=0;i<rs.size();i++)
		{
			int x=abs(rs[i].first-d)+abs(rs[i].second-d)+c1c2-2;
			can[i]=x;
		}
		sort(can.begin(),can.end());
		bool uniq=true;
		for(int i=0;i+1<rs.size();i++)if(can[i]==can[i+1])uniq=false;
		if(!uniq)continue;
		if(fst)cout<<"SCAN "<<d<<" 1"<<endl;
		else cout<<"SCAN 1 "<<d<<endl;
		int ret;cin>>ret;
		for(int i=0;i<rs.size();i++)
		{
			int x=abs(rs[i].first-d)+abs(rs[i].second-d)+c1c2-2;
			if(ret==x)return rs[i];
		}
	}
}
main()
{
	cin>>T;
	for(;T--;)
	{
		int N,M;
		cin>>N>>M;
		cout<<"SCAN 1 1"<<endl;
		int s1;cin>>s1;
		cout<<"SCAN "<<N<<" 1"<<endl;
		int s2;cin>>s2;
		int r1r2=(s1-s2+2*N+2)/2;
		int c1c2=s1+4-r1r2;
		pair<int,int>rs=f(r1r2,N,true,c1c2);
		pair<int,int>cs=f(c1c2,M,false,r1r2);
		cout<<"DIG "<<rs.first<<" "<<cs.first<<endl;
		int ret;cin>>ret;
		if(ret==1)
		{
			cout<<"DIG "<<rs.second<<" "<<cs.second<<endl;
			cin>>ret;
		}
		else
		{
			cout<<"DIG "<<rs.first<<" "<<cs.second<<endl;
			cin>>ret;
			cout<<"DIG "<<rs.second<<" "<<cs.first<<endl;
			cin>>ret;
		}
	}
}