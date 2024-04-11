#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int Q;cin>>Q;
		bool sna=false,tna=false;
		long long slen=1,tlen=1;
		for(;Q--;)
		{
			int d,k;string x;
			cin>>d>>k>>x;
			bool fn=false;
			for(char c:x)if(c!='a')fn=true;
			if(d==1)
			{
				if(fn)sna=true;
				slen+=(long long)x.size()*k;
			}
			else
			{
				if(fn)tna=true;
				tlen+=(long long)x.size()*k;
			}
			cout<<(tna?"YES\n":sna?"NO\n":slen<tlen?"YES\n":"NO\n");
		}
	}
}