#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=1009;

inline long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48; c=getchar();}
	return res*w;
}

int T,n,m;
char s[N],t[N];

bool check(int pos1,int pos2) {
	int i=pos1,j=1;
	for(;i<=pos2&&j<=m;i++,j++) {
		if(s[i]!=t[j]) return 0;
	}
	i=pos2, j=pos2-pos1+1;
	for(;j<=m;i--,j++) {
		if(s[i]!=t[j]) return 0;
	}
	return 1;
}

int main() {
	T=read();
	while(T--) {
		memset(s,0,sizeof(s)), memset(t,0,sizeof(t));
		scanf("%s%s",s+1,t+1);
		n=strlen(s+1), m=strlen(t+1);
		bool flag=0;
		rep(i,1,n) {
			rep(j,i,n) {
				if(check(i,j)) {
					puts("YES");
					flag=1;
					break;
				}
			}
			if(flag) break;
		}
		if(!flag) puts("NO");
	}
	return 0;
}