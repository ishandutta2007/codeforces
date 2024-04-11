#include<cstdio>
#include<algorithm>
#define MOD 1000003
using namespace std;
typedef long long LL;
LL n,k;
template<class T>
void Read(T &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
}
inline void read(){
	Read(n),Read(k);
}
inline int quick_pow(int a,LL b){
	int ret(1);
	while(b){
		if(b&1)
			ret=1ll*ret*a%MOD;
		a=1ll*a*a%MOD;
		b>>=1;
	}
	return ret;
}
inline void solve(){
	if(n<=60)
		if(k>(1ll<<n)){
			puts("1 1");
			exit(0);
		}
	int i,ret=1;;
	LL num;
	if(k>=MOD){
		num=k-1-__builtin_popcountll(k-1)+n;
		if(num>=1.0*n*k)
			puts("1 1");
		else
			printf("%d %d\n",quick_pow(2,((n%(MOD-1)*(k%(MOD-1))-num)%(MOD-1)+MOD-1)%(MOD-1)),quick_pow(2,((n%(MOD-1)*(k%(MOD-1))-num)%(MOD-1)+MOD-1)%(MOD-1)));
	}
	else{
		num=k-1-__builtin_popcountll(k-1)+n;
		for(i=1;i<k;i++)
			ret=(1ll*ret*(quick_pow(2,n-__builtin_ctz(i))-i/quick_pow(2,__builtin_ctz(i)))%MOD+MOD)%MOD;
		printf("%d %d\n",((quick_pow(2,((n%(MOD-1)*(k%(MOD-1))-num)%(MOD-1)+MOD-1)%(MOD-1))-ret)%MOD+MOD)%MOD,quick_pow(2,((n%(MOD-1)*(k%(MOD-1))-num)%(MOD-1)+MOD-1)%(MOD-1)));
	}
}
int main()
{
	read();
	solve();
}