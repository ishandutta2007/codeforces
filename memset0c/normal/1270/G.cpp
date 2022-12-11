#include<bits/stdc++.h>
template<class T> inline void read(T &x){
	x=0;register char c=getchar();register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
template<class T> inline void print(T a,int l,int r){for(int i=l;i<=r;i++)print(a[i]," \n"[i==r]);}
const int N=1e6+10;
int T,n,a[N],b[N],ind[N];
std::queue<int> q;
std::vector<int> ans;
signed main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	for(read(T);T--;){
		read(n),memset(ind+1,0,n<<2),ans.clear();
		for(int i=1;i<=n;i++)read(a[i]),b[i]=i-a[i],++ind[b[i]];
		for(int i=1;i<=n;i++)if(ind[i]==0)q.push(i);
		while(q.size()){
			int u=q.front(); q.pop();
			if(!--ind[b[u]])q.push(b[u]);
		}
		for(int i=1;i<=n;i++)if(ind[i])ans.push_back(i);
		print(ans.size(),'\n');
		for(int i=0;i<ans.size();i++)print(ans[i]," \n"[i+1==ans.size()]);
	}
}