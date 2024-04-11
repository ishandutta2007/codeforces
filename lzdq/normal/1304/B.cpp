#include<cstdio>
#include<iostream>
using namespace std;
int n,m;
string s[105];
string rev(const string &s){
	string res;
	for(int i=m-1;i>=0;i--) res+=s[i];
	return res;
}
int pal;
int tot,f[105][2];
int ans;
int main(){
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>s[i];
		string r=rev(s[i]);
		if(r==s[i]) pal=i;
		for(int j=1; j<i; j++)
			if(r==s[j]) tot++,f[tot][0]=j,f[tot][1]=i,ans+=2;
	}
	if(pal) ans++;
	printf("%d\n",ans*m);
	for(int i=1; i<=tot; i++)
		cout<<s[f[i][0]];
	if(pal) cout<<s[pal];
	for(int i=1; i<=tot; i++)
		cout<<s[f[tot-i+1][1]];
	cout<<endl;
	return 0;
}