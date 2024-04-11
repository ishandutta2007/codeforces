#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
const int N=1e5+5;
int n,m;
char s[595][505];
inline int solve(int i){
	int pos=m;
	for(int j=m;j>=1;j--) if(s[i][j]=='X'||s[i-1][j]=='X') pos=j;
	s[i][pos]=s[i-1][pos]='X';
	return pos;
}
int main(){
	int T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
		for(int i=1;i<=n;i+=3) 
				for(int j=1;j<=m;j++)
					s[i][j]='X';
		for(int i=4;i<=n;i+=3){
			solve(i-1);
		}
		if(n%3==0){
			int pos=solve(n);
			for(int i=1;i<=m;i++){
				if(s[n-1][i]=='X') s[n-1][i]=s[n][i]='X',pos=i;
				else if(s[n][i]=='X'){
					while(pos<i) ++pos,s[n][pos]='X';
				}
			}
		}
		for(int i=1;i<=n;i++,puts("")) 
			for(int j=1;j<=m;j++)
				putchar(s[i][j]);
	}
	return 0;
}