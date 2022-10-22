#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=2e5+5;
int n;
char s[MAXN];
void Calc1(){
	s[n]='>';
	for(int i=1,m=n,k=0; i<=n; i++){
		if(s[i]=='>'){
			for(int i=m-k; i<=m; i++)
				cout<<i<<' ';
			m-=k+1;
			k=0;
		}else k++;
	}
	cout<<endl;
	return ;
}
void Calc2(){
	s[n]='<';
	for(int i=1,m=1,k=0; i<=n; i++){
		if(s[i]=='<'){
			for(int i=m+k; i>=m; i--)
				cout<<i<<' ';
			m+=k+1;
			k=0;
		}else k++;
	}
	cout<<endl;
	return ;
}
int main(){
	int t; scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		scanf("%s",s+1);
		Calc1();
		Calc2();
	}
	return 0;
}