#include<iostream>
#include<queue>
using namespace std;
string S;
int cnt[2<<17];
bool op[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>S;
		if(S.size()%2==1)
		{
			cout<<"NO\n";
			continue;
		}
		int co=S.size()/2,cc=S.size()/2;
		for(char c:S)
		{
			if(c=='(')co--;
			else if(c==')')cc--;
		}
		if(co<0||cc<0)
		{
			cout<<"NO\n";
			continue;
		}
		{
			bool neg=false;
			cnt[0]=0;
			for(int i=0;i<S.size();i++)
			{
				cnt[i+1]=cnt[i];
				if(S[i]=='(')cnt[i+1]++,op[i]=true;
				else if(S[i]==')')cnt[i+1]--,op[i]=false;
				else if(co>0)co--,cnt[i+1]++,op[i]=true;
				else cc--,cnt[i+1]--,op[i]=false;
				if(cnt[i+1]<0)neg=true;
			}
			if(neg||cnt[S.size()]!=0)
			{
				cout<<"NO\n";
				continue;
			}
		}
		bool fn=false;
		priority_queue<pair<int,int> >Q;
		int r=S.size();
		for(int l=S.size();l--;)
		{
			if(!op[l]&&S[l]=='?')r=l;
			if(op[l]&&S[l]=='?'&&r<S.size())
			{
				while(Q.top().second>r)Q.pop();
				if(-Q.top().first>=2)fn=true;
			}
			Q.push(make_pair(-cnt[l],l));
		}
		cout<<(fn?"NO\n":"YES\n");
	}
}