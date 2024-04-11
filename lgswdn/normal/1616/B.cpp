#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define jmp(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define pmj(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();} 
	return res*w;
}

const int N=1e5+9;
int T,n;
char s[N];

signed main() {
	T=read();
	while(T--) {
		n=read();
		rep(i,1,n+1) s[i]=0;
		scanf("%s",s+1);
		rep(i,1,n) {
			if(s[i]<s[i+1]||(s[i]==s[i+1]&&i==1)||i==n) {
				rep(j,1,i) putchar(s[j]);
				per(j,i,1) putchar(s[j]);
				puts("");
				break;
			}
		}
	}
	return 0;
}