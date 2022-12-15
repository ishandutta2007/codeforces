#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2e5+10;
int n,t=0;
char s[N];
int main(){
	cin>>n;
	scanf("%s",s+1);
	int m=n/2;
	int L=0,R=0;
	for(int i=1;i<=m;++i) {
		if(s[i]=='?'){
			++t;
		}
		else R=R-s[i]+'0';
	}
	for(int i=1+m;i<=n;++i) {
		if(s[i]=='?'){
			++t;
			R=R+9;
		}
		else R=R+s[i]-'0';
	}
	if((t/2)*9==R) cout<<"Bicarp"<<endl;
	else cout<<"Monocarp"<<endl;
}