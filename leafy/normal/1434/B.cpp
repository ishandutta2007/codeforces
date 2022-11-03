#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f; 
}
const int N=2e5+5;
int n,m;
int a[N],b[N],c[N],t[N];
set<int> s;
inline bool check(){
	set<int> l;
	for(int i=1;i<=2*n;i++){
		if(b[i]) {
			l.insert(b[i]);
		}else {
			if(*l.begin()!=t[i]) return 0;
			l.erase(l.begin());
		}
	}
	return 1;
}
signed main(){
	n=read();char op[10];
	for(int i=1;i<=2*n;i++){
		scanf("%s",op+1);
		if(op[1]=='+') s.insert(i);
		else {
			int x=read();
			a[x]=i;t[i]=x;
		}
	}
	for(int i=1;i<=n;i++){
		auto it=s.upper_bound(a[i]);
		if(it==s.begin()){
			puts("NO");
			return 0;
		}
		--it;
		b[*it]=i;
		s.erase(it);
	}
	for(int i=1;i<=2*n;i++) if(b[i]) c[++m]=b[i];
	if(!check()) puts("NO");
	else {
		puts("YES");
		for(int i=1;i<=n;i++) printf("%d ",c[i]);
	}
	return 0;
}