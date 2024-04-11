#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//Longest Common Prefix(s,s.substr(i)) O(|s|)
#include<vector>
#include<string>
vector<int>Zalgo(const string&s)
{
	vector<int>ret(s.size());
	if(s.empty())return ret;
	ret[0]=s.size();
	int i=1,j=0;
	while(i<s.size())
	{
		while(i+j<s.size()&&s[j]==s[i+j])j++;
		ret[i]=j;
		if(j==0)
		{
			i++;
			continue;
		}
		int k=1;
		while(i+k<s.size()&&k+ret[k]<j)ret[i+k]=ret[k],k++;
		i+=k;j-=k;
	}
	return ret;
}
struct node{
	int nxt[26];
	int ans;
	node()
	{
		for(int i=0;i<26;i++)nxt[i]=-1;
		ans=0;
	}
};
vector<node>v(1,node());
string S;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>S;
	vector<int>za=Zalgo(S);
	for(int i=1;i<S.size();i++)if(za[i]==S.size()-i)
	{
		int p=0;
		for(int j=1;j<=10&&j<=i;j++)
		{
			int c=S[S.size()-i+j-1]-'a';
			if(v[p].nxt[c]==-1)
			{
				v[p].nxt[c]=v.size();
				v.emplace_back();
			}
			p=v[p].nxt[c];
			v[p].ans=max(v[p].ans,(int)S.size()-i+j);
		}
	}
	int Q;cin>>Q;
	for(;Q--;)
	{
		string t;cin>>t;
		int p=0;
		int k=0;
		auto s=[&t](int i){return i<S.size()?S[i]:t[i-S.size()];};
		int ans=0;
		for(int i=1;i<=t.size();i++)
		{
			if(s(ans)==t[i-1])ans++;
			else ans=0;
			int now=0;
			if(p!=-1)p=v[p].nxt[t[i-1]-'a'];
			if(p!=-1)now=v[p].ans;
			k++;
			while(true)
			{
				bool ok=true;
				for(int j=0;j<k;j++)
				{
					if(s(j)!=t[i-k+j])
					{
						ok=false;
						break;
					}
				}
				if(ok)break;
				k--;
			}
			now=max(now,k);
			ans=max(ans,now);
			cout<<ans<<(i==t.size()?"\n":" ");
		}
	}
}