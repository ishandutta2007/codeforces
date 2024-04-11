#include<bits/stdc++.h>
using namespace std;
int n;
string s,s0,t="abacaba";
vector<int> V;
inline bool semimatch(string s)
{
	register int i;
	for(i=0;i<(int)t.size();i++)
		if(s[i]!='?'&&s[i]!=t[i])
			return 0;
	return 1;
}
inline bool check(string s)
{
	int cnt=0;
	register int i;
	for(i=0;i<(int)s.size()&&i+(int)t.size()<=n;i++)
		if(s.substr(i,(int)t.size())==t)
			cnt++;
	return cnt==1;
}
inline void solve()
{
	int cnt=0,cnt2=0;
	register int i;
	cin>>n>>s;V.clear();
	for(i=0;i<(int)s.size()&&i+(int)t.size()<=n;i++)
		if(s.substr(i,(int)t.size())==t)
			cnt++;
		else if(semimatch(s.substr(i,(int)t.size())))
			V.push_back(i),cnt2++;
	if(cnt>1)
		return puts("No"),void();
	if(cnt==1)
	{
		puts("Yes");
		for(i=0;i<(int)s.size();i++)
			putchar(s[i]=='?'?'x':s[i]);
		putchar('\n');
		return;
	}
	if(cnt2==0)
		return puts("No"),void();
	for(int x:V)
	{
		s0=s.substr(0,x)+t+s.substr(x+(int)t.size(),(int)s.size()-(int)t.size()-x);
		for(i=0;i<(int)s.size();i++)
			if(s0[i]=='?')
				s0[i]='x';
		if(check(s0))
		{
			cout<<"Yes"<<endl<<s0<<endl;
			return;
		}
	}
	cout<<"No"<<endl;
	return;
}
signed main()
{
	int T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}