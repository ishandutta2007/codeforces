#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int N=1e5+5;
int a[N],n,k;
map<int,int>tot,id;
struct Node{
	int tott,num;
}p[N];
int cnt;
inline int Read(){
	char ch;
	int f=1;
	while((ch=getchar())<'0'||ch>'9')
		if(ch=='-') f=-1;
	int x=ch^48;
	while((ch=getchar())>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+(ch^48);
	return x*f;
}
inline void print(const int x){
	if(x>=10) print(x/10);
	putchar(x%10+48);
	return ;
}
inline void Print(const int x,const char ch='\n'){
	if(x<0){
		putchar('-');
		print(-x);
	}
	else print(x);
	putchar(ch);
	return ;
}
inline int Lowbit(const int x){
	return x&(-x);
}
struct BIT{
	int c[N];
	inline void Clear(){
		for(int i=1;i<=cnt;i++)
			c[i]=0;
		return ;
	}
	inline void Change(const int x,const int value){
		for(int i=x;i<=cnt;i+=Lowbit(i))
			c[i]+=value;
		return ;
	}
	inline int Query(const int x){
		int ss=0;
		for(int i=x;i;i-=Lowbit(i))
			ss+=c[i];
		return ss;
	}
}bit1,bit2;
inline bool Cmp(const Node x,const Node y){
	return x.tott<y.tott;
}
inline void Init(){
	tot.clear();
	id.clear();
	cnt=0;
	n=Read();
	k=Read();
	for(int i=1;i<=n;i++){
		int x=Read();
		tot[x]++;
	}
	for(map<int,int>::iterator it=tot.begin();it!=tot.end();it++){
		++cnt;
		p[cnt].num=(*it).first;
		p[cnt].tott=(*it).second;
	}
	bit1.Clear();
	bit2.Clear();
	sort(p+1,p+cnt+1,Cmp);
	for(int i=1;i<=cnt;i++){
		id[p[i].num]=i;
		bit1.Change(i,p[i].tott);
	}
	return ;
}
inline int Max(const int x,const int y){
	return x>y?x:y;
}
inline int Min(const int x,const int y){
	return x<y?x:y;
}
int ans,ss;
inline void Solve(){
	ans=n;
	ss=0;
	for(int i=0;i<=n;i++){
		if(ss>k) break ;
		if(tot[i]>k) continue ;
		int kk=k-tot[i];
		if(tot[i]){
			bit1.Change(id[i],-tot[i]);
			bit2.Change(id[i],1);
		}
		else ss++;
		int ll=0,rr=cnt;
		while(ll<rr){
			int mid=ll+rr+1>>1;
			if(bit1.Query(mid)<=kk) ll=mid;
			else rr=mid-1;
		}
		ans=Min(ans,cnt-(i+1-ss)-(ll-bit2.Query(ll)));
	}
	Print(ans);
	return ;
}
int T;
int main(){
	for(T=Read();T;T--){
		Init();
		Solve();
	}
	return 0;
}