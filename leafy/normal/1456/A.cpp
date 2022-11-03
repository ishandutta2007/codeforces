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
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s;
}
const int N=1e6+5;
int n,p,k,x,y;
char a[N];
int cnt[N];
int main(){
	int T=read();
	while(T--){
		n=read(),p=read(),k=read();
		scanf("%s",a+1);
		x=read(),y=read();
		for(int i=0;i<=n;i++) cnt[i]=0;
		int ans=0x3f3f3f3f;
		for(int i=n-p,j=n;i>=0;i--,j--){
			if(a[j]=='0') cnt[j%k]+=x;
			ans=min(ans,i*y+cnt[(i+p)%k]);
		}
		printf("%d\n",ans);
	}
	return 0;
}