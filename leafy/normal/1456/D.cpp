//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
const int N=5005,inf=0x3f3f3f3f;
int n;
int x[N],t[N],mt[N];
bool f[N][N];
int main(){
	n=read();
	for(int i=1;i<=n;i++) t[i]=read(),x[i]=read();
	memset(mt,0x3f,sizeof(mt));mt[0]=0;
	for(int i=0;i<n;i++){
		if(mt[i]<=t[i]) {
			mt[i+1]=min(mt[i+1],max(t[i],mt[i]+abs(x[i+1]-x[i])));
			for(int j=i+2;j<=n;j++)
				if(max(t[i],mt[i]+abs(x[j]-x[i]))+abs(x[j]-x[i+1])<=t[i+1])
					f[i+1][j]=1;
		}
		if(i<n-1&&f[i][i+1]){
			mt[i+2]=min(mt[i+2],max(t[i+1],t[i]+abs(x[i+2]-x[i])));
			for(int j=i+3;j<=n;j++)
				if(max(t[i+1],t[i]+abs(x[j]-x[i]))+abs(x[j]-x[i+2])<=t[i+2])
					f[i+2][j]=1;
		}
		if(t[i]+abs(x[i+1]-x[i])<=t[i+1])
			for(int j=i+2;j<=n;j++)
				f[i+1][j]|=f[i][j];
	}
	if(mt[n]<=t[n]||f[n-1][n]) puts("YES");
	else puts("NO");
	return 0;
}