#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;
pair<long long,long long>eval(string s)
{
	long long a=0,b=0,c=0,d=0,x=-1;
	int id=0;
	while(s[id]!='.')a=a*10+s[id++]-'0';
	id++;
	while(s[id]!='.')b=b*10+s[id++]-'0';
	id++;
	while(s[id]!='.')c=c*10+s[id++]-'0';
	id++;
	while(id<s.size()&&s[id]!='/')d=d*10+s[id++]-'0';
	long long beg=a<<24|b<<16|c<<8|d;
	long long ed=beg;
	if(id<s.size()&&s[id]=='/')
	{
		x=0;
		id++;
		while(id<s.size())x=x*10+s[id++]-'0';
		x=32-x;
		ed=beg+(1LL<<x)-1;
	}
	return make_pair(beg,ed);
}
string to_s(pair<long long,long long>p)
{
	long long beg=p.first;
	string ret="";
	for(int i=24;i>=0;i-=8)
	{
		ret+=to_string(beg>>i&(1<<8)-1);
		ret+='.';
	}
	ret.pop_back();
	if(beg<p.second)
	{
		int x=0;
		while(!(beg>>x&1)&&p.second>>x&1)x++;
		ret+='/';
		ret+=to_string(32-x);
	}
	return ret;
}
bool cont(pair<long long,long long>lhs,pair<long long,long long>rhs)
{
	return lhs.first<=rhs.first&&rhs.second<=lhs.second;
}
void disp(pair<long long,long long>p)
{
	cout<<"("<<p.first<<", "<<p.second<<")"<<endl;
}
int N;
vector<pair<bool,pair<long long,long long> > >A;
vector<string>ans;
void calc(long long L,long long R,vector<pair<long long,long long> >T)
{
	vector<pair<long long,long long> >A;
	for(pair<long long,long long>p:T)
	{
		if(p.first<=L||R<=p.second)
		{
			cout<<"-1\n";
			exit(0);
		}
		int x=0;
		while(L<(p.first&~((1LL<<x)-1))&&(p.second|(1LL<<x)-1)<R)x++;
		x--;
		pair<long long,long long>now=make_pair(p.first&~((1LL<<x)-1),p.second|(1LL<<x)-1);
		while(!A.empty()&&cont(now,A.back()))A.pop_back();
		if(A.empty()||!cont(A.back(),now))A.push_back(now);
	}
	for(pair<long long,long long>a:A)
	{
		ans.push_back(to_s(a));
	}
}
main()
{
	cin>>N;
	A.push_back(make_pair(false,make_pair(-1,-1)));
	A.push_back(make_pair(false,make_pair(1LL<<32,1LL<<32)));
	for(int i=0;i<N;i++)
	{
		string s;cin>>s;
		pair<long long,long long>now=eval(s.substr(1));
		if(s[0]=='+')A.push_back(make_pair(false,now));
		else A.push_back(make_pair(true,now));
	}
	sort(A.begin(),A.end(),[](pair<bool,pair<long long,long long> >a,pair<bool,pair<long long,long long> >b)
	{
		return a.second<b.second;
	});
	for(int i=0;i+1<A.size();)
	{
		int j=i+1;
		vector<pair<long long,long long> >T;
		while(A[j].first)
		{
			T.push_back(A[j++].second);
		}
		calc(A[i].second.second,A[j].second.first,T);
		i=j;
	}
	cout<<ans.size()<<"\n";
	for(string s:ans)cout<<s<<"\n";
}