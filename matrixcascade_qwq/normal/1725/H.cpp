#include<cstdio>
#include<cassert>
const int N=1e5+5;
int a[N],n,cnt[3];
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
inline bool Get0(){
	if(cnt[0]>n/2) return 0;
	int tot=n/2-cnt[0];
	puts("0");
	for(int i=1;i<=n;i++){
		if(a[i]==0) putchar('0');
		else if(tot){
			putchar('0');
			tot--;
		}
		else putchar('1');
	}
	putchar('\n');
	return 1;
}
inline bool Get1(){
	if(cnt[0]) return 0;
	puts("1");
	for(int i=1;i<=n/2;i++)
		putchar('0');
	for(int i=1;i<=n/2;i++)
		putchar('1');
	putchar('\n');
	return 1;
}
inline bool Get2(){
	if(cnt[1]+cnt[2]>n/2) return 0;
	int tot=n/2-cnt[1]-cnt[2];
	puts("2");
	for(int i=1;i<=n;i++){
		if(a[i]==1||a[i]==2) putchar('0');
		else if(tot){
			putchar('0');
			tot--;
		}
		else putchar('1');
	}
	return 1;
}
inline void Init(){
	n=Read();
	for(int i=1;i<=n;i++){
		a[i]=Read();
		a[i]%=3;
		cnt[a[i]]++;
	}
	return ;
}
inline void Solve(){
	if(Get0()) return ;
	if(Get1()) return ;
	if(Get2()) return ;
	puts("-1");
	return ;
}
int main(){
	Init();
	Solve();
	return 0;
}