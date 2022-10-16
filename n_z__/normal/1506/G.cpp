#include<bits/stdc++.h>
using namespace std;
int h[131],vis[131];
int main()
{
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		memset(h,0,sizeof(h));
		memset(vis,0,sizeof(vis));
		vector<char>a;
		for(int x=0;x<s.size();x++)h[s[x]]++;
		for(int x=0;x<s.size();x++){
			h[s[x]]--;
			if(!vis[s[x]]){
				while(!a.empty()&&h[a.back()]!=0&&a.back()<=s[x])vis[a.back()]=0,a.pop_back();
				a.push_back(s[x]);
				vis[s[x]]=s[x];
			}
		}
		cout<<string(a.begin(),a.end())<<endl;
	}
}