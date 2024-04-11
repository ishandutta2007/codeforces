#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
#define MOD 1000000007
#define MAXK 200
int k,C[MAXK+10][MAXK+10],S[MAXK+10][MAXK+10],ans;
LL l,r;
void prepare(){
	int i,j;
	for(i=0;i<=k;i++){
		S[i][i]=1;
		C[i][0]=1;
		for(j=1;j<=i;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
			S[i][j]=((S[i-1][j-1]-1ll*S[i-1][j]*(i-1))%MOD+MOD)%MOD;
		}
	}
}
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
	Read(k),Read(l),Read(r);
	//f[i][0]=f[i-1][1]
	//f[i][1]=f[i-1][0]+f[i][1]
	//f[i][0]+f[i][1]=F[i+2]
	//F[i]=(((1+sqrt(5))/2)^n-((1-sqrt(5))/2)^n)/sqrt(5)
}
int quick_pow(int a,int b){
	int ret(1);
	while(b){
		if(b&1)
			ret=1ll*ret*a%MOD;
		a=1ll*a*a%MOD;
		b>>=1;
	}
	return ret;
}
struct data{
	int a,b; //a+bsqrt(5)
	inline data(){
	}
	inline data(int a,int b=0):a(a),b(b){
	}
	inline data operator + (const data &x)const{
		return data((a+x.a)%MOD,(b+x.b)%MOD);
	}
	inline data & operator +=(const data &x){
		return *this=*this+x;
	}
	inline data operator - (const data &x)const{
		return data((a-x.a+MOD)%MOD,(b-x.b+MOD)%MOD);
	}
	inline data & operator -=(const data &x){
		return *this=*this-x;
	}
	inline data operator * (const data &x)const{
		return data((1ll*a*x.a+5ll*b*x.b)%MOD,(1ll*a*x.b+1ll*b*x.a)%MOD);
	}
	inline data & operator *= (const data &x){
		return *this=*this*x;
	}
	inline data operator / (const data &x)const{
		static data ret;
		int inv;
		ret=*this*data(x.a,MOD-x.b);
		inv=quick_pow(((1ll*x.a*x.a-5ll*x.b*x.b)%MOD+MOD)%MOD,MOD-2);
		ret.a=1ll*ret.a*inv%MOD;
		ret.b=1ll*ret.b*inv%MOD;
		return ret;
	}
	inline data & operator /= (const data &x){
		return *this=*this/x;
	}
};
data quick_pow(data a,LL b){
	data ret(1);
	while(b){
		if(b&1)
			ret*=a;
		a*=a;
		b>>=1;
	}
	return ret;
}
int cal(LL n,int m){
	int i;
	data ret(0);
	data a((MOD+1)>>1,(MOD+1)>>1),b((MOD+1)>>1,1ll*(MOD-1)*((MOD+1)>>1)%MOD),gb,st;
	for(i=0;i<=m;i++){
		gb=quick_pow(a,i)*quick_pow(b,m-i);
		st=quick_pow(gb,3);
		data t=(quick_pow(gb,n+3)-st)/(gb-1);
		if(gb.a==1&&gb.b==0){
			t=n%MOD;
		}
		if((m-i)&1)
			ret-=t*C[m][i];
		else
			ret+=t*C[m][i];
	}
	ret/=quick_pow(data(0,1),m);
	return ret.a;
}
void solve(){
	int i,fac=1;
	for(i=1;i<=k;i++)
		ans=((ans+1ll*S[k][i]*(cal(r,i)-cal(l-1,i)))%MOD+MOD)%MOD;
	ans=(ans+(r-l+1)%MOD*S[k][0])%MOD;
	for(i=1;i<=k;i++)
		fac=1ll*i*fac%MOD;
	ans=1ll*ans*quick_pow(fac,MOD-2)%MOD;
}
int main()
{
	read();
	prepare();
	solve();
	printf("%d\n",ans);
}