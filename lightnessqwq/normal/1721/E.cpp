#include<stdio.h>
#include<iostream>
using namespace std;
const int maxn=1001005;
int T,n,m;
int nxt[maxn][27],p[maxn];
string s,t;
int main(){
	ios::sync_with_stdio(false);
	cin>>s,n=s.size(),s=" "+s;
	p[1]=0;
	for(int i=2,j=0;i<=n;i++){
		while(j&&s[j+1]!=s[i])
			j=p[j];
		if(s[j+1]==s[i])
			j++;
		p[i]=j;
	}
	for(int i=0;i<n;i++)
		for(int j=1;j<=26;j++){
			if(s[i+1]==j+96)
				nxt[i][j]=i+1;
			else nxt[i][j]=nxt[p[i]][j];
		}
	cin>>T;
	s.resize(n+15);
	while(T--){
		cin>>t,m=t.size();
		for(int i=n+1,j=p[n];i<=n+m;i++){
			s[i]=t[i-n-1];
			while(j>=n&&s[j+1]!=s[i])
				j=p[j];
			if(s[j+1]!=s[i])
				j=nxt[j][s[i]-96];
			else j++;
			p[i]=j;
			printf("%d%c",j,i==n+m? '\n':' ');
		}
	}
	return 0;
}