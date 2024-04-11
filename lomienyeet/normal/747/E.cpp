#include <bits/stdc++.h>
using namespace std;
const int MAXN=696969;
vector<string> ve[MAXN];
string s;
int maxi=0,l,cur=0,N;
void DFS(int dep){
	if(cur>=l)return;
	string tmp="";
	while(s[cur]!=',')tmp+=s[cur],cur++;
	cur++;
	int go=0;
	while(cur<l&&s[cur]!=',')go=go*10+s[cur]-'0',cur++;
	ve[dep+1].push_back(tmp);
	cur++;
	maxi=max(dep+1,maxi);
	for(int i=1;i<=go;i++)DFS(dep+1);
}
int main(){
	cin>>s;
	l=s.length();
	while(cur<=l)DFS(0);
	cout<<maxi<<"\n";
	for(int i=1;i<=maxi;i++){
		for(auto j:ve[i])cout<<j<<" ";
		cout<<"\n";
	}
	return 0;
}