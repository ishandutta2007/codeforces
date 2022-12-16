#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
typedef vector<int> V;

template<class T=int>
T read(){
	T x=0;
	char ch=0;
	bool f=false;
	while(!isdigit(ch))f|=(ch=getchar())=='-';
	for(;isdigit(ch);ch=getchar())x=x*10+(ch^'0');
	return f?-x:x;
}

const int N=555;
char s[N][N];
char ans[N][N];
int main(){
	int t=read();
	while(t--){
		int n=read(),m=read();
		F(i,1,n+1)F(j,1,m+1)s[i][j]='.';
		F(i,1,n)scanf("%s",s[i]+1);
		bool ss=n<m;
		if(ss){
			swap(n,m);
			F(i,1,n)F(j,1,min(i,m))swap(s[i][j],s[j][i]);
		}
		int k=n%4==1?1:2;
		F(i,1,n)F(j,1,m)ans[i][j]='.';
		if(m==1)F(i,1,n)ans[i][1]='X';
		else{
			F(i,1,n){
				F(j,1,m)if(s[i][j]=='X')ans[i][j]='X';
				if(i%4==k)F(j,1,m)ans[i][j]='X';
				if(i%4==(k+2)%4){
					bool h=false;
					F(j,1,m){
						if(s[i][j]=='X'){
							ans[i-1][j]='X';
							if(!h)ans[i+1][j]='X';
							h=true;
						}
					}
					if(!h){
						ans[i][1]=ans[i][2]='X';
						if(s[i-1][1]!='X'&&s[i-1][2]!='X')ans[i-1][1]='X';
						if(s[i+1][1]!='X'&&s[i+1][2]!='X')ans[i+1][1]='X';
					}
				}
			}
		}
		if(ss)F(i,1,n)F(j,1,min(i,m))swap(ans[i][j],ans[j][i]);
		if(ss)swap(n,m);
		F(i,1,n){F(j,1,m)putchar(ans[i][j]);puts("");}
	}
	return 0;
}