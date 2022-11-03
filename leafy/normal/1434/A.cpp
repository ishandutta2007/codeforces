#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f; 
}
const int N=1e5+5;
int n;
int a[N],b[N],c[N],num=0;
struct node{
	int x,id;
}s[N*6];
inline bool cmp(node a,node b){
	return a.x<b.x;
}
signed main(){
	for(int i=1;i<=6;i++) a[i]=read();
	n=read();
	for(int i=1;i<=n;i++) b[i]=read();
	sort(a+1,a+7);sort(b+1,b+n+1);
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=6;j++){
			s[++cnt]={b[i]-a[j],i};
		}
	}
	sort(s+1,s+cnt+1,cmp);
	int l=1,r=0,ans=1e9;
	while(l<=cnt&&r<=cnt){
		while(r+1<=cnt&&num<n){
			if(!c[s[r+1].id]) num++;
			c[s[r+1].id]++;
			r++;
		}
		
		if(num<n) break;
		ans=min(ans,s[r].x-s[l].x);
		c[s[l].id]--;
		if(!c[s[l].id]) num--;
		l++;
	}
	cout<<ans;
	return 0;
}