#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
int N;
vector<pair<long long,int> >S;
long long T[3<<17];
vector<pair<pair<int,int>,long long> >ans;
vector<pair<pair<long long,long long>,int> >L,R;
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		long long s;scanf("%lld",&s);
		S.push_back(make_pair(s,i+1));
	}
	for(int i=0;i<N;i++)scanf("%lld",T+i);
	sort(S.begin(),S.end());
	sort(T,T+N);
	for(int i=0;i<N;i++)
	{
		if(T[i]>S[i].first)
		{
			L.push_back(make_pair(make_pair(S[i].first,T[i]-S[i].first),i));
		}
		else if(T[i]<S[i].first)
		{
			R.push_back(make_pair(make_pair(S[i].first,S[i].first-T[i]),i));
		}
	}
	sort(L.begin(),L.end());
	sort(R.begin(),R.end());
	int id=0;
	for(int i=0;i<L.size();i++)
	{
		while(L[i].first.second>0)
		{
			while(id<R.size()&&(R[id].first.second==0||R[id].first.first-L[i].first.first<=0))id++;
			if(id==R.size())break;
			long long now=min(min(L[i].first.second,R[id].first.second),(R[id].first.first-L[i].first.first)/2);
			L[i].first.second-=now;
			S[L[i].second].first+=now;
			L[i].first.first+=now;
			R[id].first.second-=now;
			S[R[id].second].first-=now;
			R[id].first.first-=now;
			ans.push_back(make_pair(make_pair(S[L[i].second].second,S[R[id].second].second),now));
		}
	}
	bool flag=1;
	for(int i=0;i<N;i++)flag&=S[i].first==T[i];
	if(flag)
	{
		puts("YES");
		cout<<ans.size()<<endl;
		for(pair<pair<int,int>,long long>&p:ans)
			printf("%d %d %lld\n",p.first.first,p.first.second,p.second);
	}
	else puts("NO");
}