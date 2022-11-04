#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=1009,n=10,S=(1<<10)-1;

inline long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48; c=getchar();}
	return res*w;
}

int T,b[2],r[2],ans;
bool a[N];
char s[N];

int main() {
	T=read();
	while(T--) {
		scanf("%s",s+1);
		ans=n;
		rep(ss,0,S) {
			rep(i,1,n) {
				if(ss&(1<<i-1)) a[i]=1;
				else a[i]=0;
			}
			bool flag=0;
			rep(i,1,n) if(s[i]=='1'&&a[i]==0||s[i]=='0'&&a[i]==1) {flag=1; break;}
			if(flag==1) continue;
			b[0]=b[1]=5, r[0]=r[1]=1;
			rep(i,1,n) {
				if(a[i]) r[i%2]++;
				b[i%2]=r[i%2]+5-(i+1)/2;
				if(b[0]<r[1]||b[1]<r[0]||i==n) {
					ans=min(ans,i);
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}