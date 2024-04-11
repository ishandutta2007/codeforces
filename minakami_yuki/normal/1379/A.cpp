#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<ctime> 
#define LL long long 
using namespace std;
const int N=1e5+10;
int n;
char s[N],A[N];
char t[N]="abacaba";
bool ch(int x){
	for(int i=0;i<=6;++i){
		if(s[x+i]!=t[i]) return 0; 
	}
	return 1;
}
bool J(int x){
	for(int i=0;i<=6;++i){
		A[x+i]=s[x+i];
		if(s[x+i]!=t[i]&&s[x+i]!='?') return 0; 
	}
	for(int i=0;i<=6;++i) s[x+i]=t[i];
	bool flag=1;
	for(int i=x+1;i<=x+6;++i)
		if(ch(i)) flag=0;
	for(int i=max(1,x-6);i<x;++i)
		if(ch(i)) flag=0;
	if(flag){
		/*
		1
		13
		abacab?bacaba
		*/
		for(int i=1;i<=n;++i) if(s[i]=='?') s[i]='z';
		return 1;
	}
	for(int i=0;i<=6;++i) s[x+i]=A[x+i];
	return 0;
}
int main(){
	//for(int i=1;i<=7;++i) cout<<t[i];
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",s+1);
		//for(int i=1;i<=10+n;++i) cout<<s[i];puts("");
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(ch(i)) ++cnt;
		}
		if(cnt>1){
			cout<<"No"<<endl;
			continue;
		}
		else if(cnt==1){
			cout<<"Yes"<<endl;
			for(int i=1;i<=n;++i)
				if(s[i]=='?') cout<<"z";
				else printf("%c",s[i]);
			puts("");
		}
		else{
			bool f=0;
			for(int i=1;i<=n;++i) if(J(i)){
				f=1;cout<<"Yes"<<endl;
				for(int j=1;j<=n;++j) printf("%c",s[j]);puts("");
				break;
			}
			if(!f) cout<<"No"<<endl;
		}
	}
	return 0;
}