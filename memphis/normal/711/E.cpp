#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

inline void Min(int &a,int b){if(b<a) a=b;}
inline void Min(ll &a,ll b){if(b<a) a=b;}
inline void Max(int &a,int b){if(b>a) a=b;}
inline void Max(ll &a,ll b){if(b>a) a=b;}

const ll infl=0x3f3f3f3f3f3f3f3fll;
const int P=1000003;
//const int N=200005;

ll n,k;
int fm,fz,num[P],inv[100];

int power(int x,ll v){
	int ans=1;
	for(;v;v>>=1,x=(ll)x*x%P) if(v&1) ans=(ll)ans*x%P;
	return ans;
}

int main(){
	rep(i,1,P-1){
		int tmp=i;
		while(!(tmp&1)) ++num[i],tmp>>=1;
	}
	inv[0]=1;
	inv[1]=power(2,P-2);
	rep(i,2,50) inv[i]=(ll)inv[i-1]*inv[1]%P; 
	
	scanf("%I64d%I64d",&n,&k);
	if(n<63 && (1ll<<n)<k){
		//puts("!");
		puts("1 1");
		return 0;
	}
	
	fm=power(power(2,n),k-1);
	int tmp=power(2,n);
	fz=1;
	if(k>tmp){
		fz=0;
		
		ll tmp=2,cnt=0;
		while(tmp<=k-1){
			cnt+=(k-1)/tmp;
			tmp<<=1;
		}
		fm=(ll)fm*power(inv[1],cnt)%P;
		
	}
	else{
		rep(i,1,k-1){
			fz=(ll)fz*(tmp-i)%P;
			fz=(ll)fz*inv[num[i]]%P;
			fm=(ll)fm*inv[num[i]]%P;
		}
	}
	fz=(fm-fz+P)%P;
	printf("%d %d\n",fz,fm);
}