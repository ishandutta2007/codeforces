#include<iostream>
#include<map>
using namespace std;
int T,N;
struct dat{
	long long len,cnt;
	string L,R;
	dat(){}
	dat(long long a,long long b,string c,string d):len(a),cnt(b),L(c),R(d){}
};
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N;cin.ignore();
		long long ans=0;
		map<string,dat>mp;
		for(int i=0;i<N;i++)
		{
			string s;
			getline(cin,s);
			int id=0;
			while(s[id]!=' ')id++;
			string name=s.substr(0,id);
			id++;
			if(s[id]==':')
			{
				id+=3;
				string val=s.substr(id);
				int len=val.size();
				int cnt=0;
				if(len>=4&&val.substr(0,4)=="haha")cnt++;
				if(len>=5&&val.substr(1,4)=="haha")cnt++;
				string L=val.substr(0,3);
				string R=len>=3?val.substr(len-3):val;
				mp[name]=dat(len,cnt,L,R);
				ans=cnt;
			}
			else
			{
				id+=2;
				int jd=id;
				while(s[jd]!=' ')jd++;
				dat a=mp[s.substr(id,jd-id)];
				dat b=mp[s.substr(jd+3)];
				long long cnt=a.cnt+b.cnt;
				string mid=a.R+b.L;
				for(int x=0;x+4<=mid.size();x++)
				{
					if(mid.substr(x,4)=="haha")cnt++;
				}
				string L=a.L,R=b.R;
				if(L.size()==a.len&&L.size()<3)
				{
					L+=b.L.substr(0,3-L.size());
				}
				if(R.size()==b.len&&R.size()<3)
				{
					int need=3-R.size();
					if(need<=a.R.size())R=a.R.substr(a.R.size()-need)+R;
					else R=a.R+R;
				}
				mp[name]=dat(a.len+b.len,cnt,L,R);
				ans=cnt;
			}
		}
		printf("%lld\n",ans);
	}
}