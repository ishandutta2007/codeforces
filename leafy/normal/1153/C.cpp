#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n;
char s[N],t[N];
int b[N],sum[N][2],ss[N];
queue<int> q;
int main(){
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++){
		sum[i][0]=sum[i-1][0],sum[i][1]=sum[i-1][1];
		ss[i]=ss[i-1];
		if(s[i]=='(') sum[i][0]=sum[i-1][0]+1;
		if(s[i]==')') sum[i][1]=sum[i-1][1]+1;
		if(s[i]=='?') ss[i]=ss[i-1]+1;
	}
	int tmp=0;
	for(int i=1;i<=n;i++){
		if(tmp<0) break;
		if(i!=1&&tmp==0) {
			tmp=-1;
			break;
		}
		if(s[i]=='(') t[i]='(',tmp++;
		if(s[i]==')') t[i]=')',tmp--;
		if(s[i]!='?') continue;
		if(ss[n]-ss[i]+sum[n][0]-sum[i][0]+tmp<sum[n][1]-sum[i][1]) {
			t[i]='(',tmp++;
			continue;
		}
		if(sum[n][1]-sum[i][1]+ss[n]-ss[i]<sum[n][0]-sum[i][0]+tmp) {
			t[i]=')',tmp--;
			continue;
		}
		
		t[i]='(';tmp++;
	}
	if(tmp!=0) puts(":(");
	else {
	for(int i=1;i<=n;i++) putchar(t[i]);
	}
	return 0;
} 
/*
8
((???)))
*/