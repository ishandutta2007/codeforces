#include<bits/stdc++.h>
#define ll long long 
#define int long long
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
const int N=2e5+10;
int n,m,a[N],ans,b[N];
std::map<int,int> map[N];
signed main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n);
	for(int i=1;i<=n;i++)read(a[i]),ans+=a[i];
	read(m);
	for(int s,t,u,i=1;i<=m;i++){
		read(t),read(s),read(u);
		ans-=std::max(0ll,a[map[t][s]]-b[map[t][s]]);
		if(map[t][s])b[map[t][s]]--;
		ans+=std::max(0ll,a[map[t][s]]-b[map[t][s]]);
		map[t][s]=u;
		ans-=std::max(0ll,a[map[t][s]]-b[map[t][s]]);
		if(map[t][s])b[map[t][s]]++;
		ans+=std::max(0ll,a[map[t][s]]-b[map[t][s]]);
		print(ans,'\n');
	}
}