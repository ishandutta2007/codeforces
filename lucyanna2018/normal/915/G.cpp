#include<cstdio>

/*#### modular_arithmetic */
class modular_arithmetic{
public:
	int mod;

	modular_arithmetic(){
		mod = 1000000007;
	}
	//No specific settings.
	void set_mod(int _mod){mod = _mod;}
	int add(int x,int y){return (x+y)%mod;}
	int sub(int x,int y){return (x-y+mod)%mod;}
	int mul(int x,int y){return (int)((long long int)x*y%mod);}
	int pw(int x,int y){
		int r = 1;
		while(1){
			if(y&1)r=mul(r,x);
			if(y>>=1)x=mul(x,x);else
				break;
		}
		return r;
	}
	//mod must be a prime.
	int inv(int x){
		return pw(x, mod-2);
	}
	int div(int x,int y){
		return mul(x, inv(y));
	}
};
/*####*/
modular_arithmetic ma;

#define ran 2000002
int res[ran],U,n;
int p[2000],lp;
int main(){
	scanf("%d%d",&U,&n);
	res[1] = 1;
	for(int i=2; i<=n; i++){
		if(res[i] == 0){
			res[i] = ma.pw(i, U);
			if(i < 2000)p[lp++] = i;
		}
		for(int j=0; j<lp; j++){
			int x = i*p[j];
			if(x > n)break;
			res[x] = ma.mul(res[i], res[p[j]]);
			if(i%p[j]==0)break;
		}
	}
	int out = 0;
	for(int i=n; i>=1; i--){
		res[i] = ma.sub(res[i], res[i-1]);
	}
	for(int i=1; i<=n; i++)
		for(int j=i+i; j<=n; j+=i)
			res[j] = ma.sub(res[j], res[i]);
	for(int i=1; i<=n; i++)
		res[i] = ma.add(res[i], res[i-1]);
	for(int i=1; i<=n; i++)
		out = ma.add(out, res[i]^i);
	printf("%d\n",out);
	return 0;
}