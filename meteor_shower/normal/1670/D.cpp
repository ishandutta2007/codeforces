#include<cstdio>
typedef long long LL;
const int Z=3;
int cnt[Z],p,n,T;
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
inline void Init(){
	cnt[0]=cnt[1]=cnt[2]=0;
	p=0;
	//n=1000000000;
	n=Read();
	return ;
}
int ss;
inline void Solve(){
	int ll=0,rr=35000;
	while(ll<rr){
		int mid=ll+rr+1>>1;
		LL s1=mid*mid*2+2ll*mid*(mid+mid);
		if(s1<=n) ll=mid;
		else rr=mid-1;
	}
	p=0;
	cnt[0]=cnt[1]=cnt[2]=ll;
	ss=ll*ll*2+2*ll*(ll+ll);
	while(ss<n){
		cnt[p]++;
		ss+=2*(cnt[0]+cnt[1]+cnt[2]-cnt[p]);
		p=(p+1)%3;
	}
	Print(cnt[0]+cnt[1]+cnt[2]);
	return ;
}
int main(){
	for(T=Read();T;T--){
		Init();
		Solve();
	}
	return 0;
}