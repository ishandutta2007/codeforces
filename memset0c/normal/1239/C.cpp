#include<bits/stdc++.h>
// #define ll long long
#define int long long
template<class T> inline void read(T &x){
	x=0; register char c=getchar(); register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar(); if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10); putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
template<class T> inline void print(T a,int l,int r){for(int i=l;i<=r;i++)print(a[i]," \n"[i==r]);}
const int N=1e5+10;
int n,cur,now,k,a[N],ans[N];
struct pair{
	int i,x;
	inline bool operator<(const pair &other)const{
		return i<other.i;
	}
}p[N];
inline bool cmp(const pair &a,const pair &b){ 
	return a.x==b.x?a.i<b.i:a.x<b.x;
}
std::set<pair> set;
std::queue<pair> que;
std::set<int> tim,inq;
signed main(){
#ifdef memset0
	freopen("1.in","r",stdin);
	// freopen("1.out","w",stdout);
#endif
	read(n),read(k);
	for(int i=1;i<=n;i++)read(a[i]),p[i]={i,a[i]},tim.insert(a[i]);
	std::sort(p+1,p+n+1,cmp);
	// for(int i=1;i<=n;i++)printf("[%d %d]%c",p[i].i,p[i].x," \n"[i==n]);
	int lst;
	while(tim.size()){
		int it=*tim.begin(); tim.erase(tim.begin());
		if(it==now&&lst){inq.erase(lst);}
		while(cur<n&&p[cur+1].x==it)set.insert(p[++cur]);
		// printf("> %d\n",it);
		while(set.size()&&(!inq.size()||*inq.begin()>set.begin()->i)){
			que.push(*set.begin());
			// printf("push queue %d %d\n",set.begin()->i,set.begin()->x);
			inq.insert(set.begin()->i);
			set.erase(set.begin());
		}
		if(it<now)continue;
		if(que.size()){
			auto jt=que.front(); que.pop();
			// printf("pop queue %d %d\n",jt.i,jt.x);
			tim.insert(it+k);
			now=ans[jt.i]=it+k,lst=jt.i;
		}
	}
	for(int i=1;i<=n;i++)print(ans[i]," \n"[i==n]);
}