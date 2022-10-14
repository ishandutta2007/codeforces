#include<cstdio>
const int N=1e5+5;
typedef long long LL;
int n;
LL a[N];
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
inline void print(LL x){
	if(x>=10) print(x/10);
	putchar(x%10+48);
	return ;
}
inline void Print(LL x,char ch='\n'){
	if(x<0){
		putchar('-');
		print(-x);
	}
	else print(x);
	putchar(ch);
	return ;
}
inline void Init(){
	n=Read();
	for(int i=1;i<=n;i++){
		a[i]=Read();
		a[i]+=a[i-1];
	}
	return ;
}
LL ans,b[N];
inline void Work(int ll,int rr){
	if(ll==rr) return ;
	int mid=ll+rr>>1;
	Work(ll,mid);
	Work(mid+1,rr);
	int i=ll,j=mid+1,k=ll;
	while(i<=mid&&j<=rr){
		if(a[i]<=a[j]){
			b[k++]=a[i++];
			ans+=j-(mid+1);
		}
		else b[k++]=a[j++];
	}
	while(i<=mid) b[k++]=a[i++],ans+=rr-mid;
	while(j<=rr) b[k++]=a[j++];
	for(i=ll;i<=rr;i++) a[i]=b[i];
	return ;
}
inline void Solve(){
	for(int i=1;i<=n;i++){
		if(a[i]<0){
			puts("-1");
			return ;
		}
		if(a[i]>a[n]){
			puts("-1");
			return; 
		}
	}
	if(n>1) Work(1,n-1);
	return Print(ans);
}
int main(){
	Init();
	Solve();
	return 0;
}