#include<cstdio>
#include<map>
using namespace std;
int n,m;char s[55][1111];
map<long long int,int> a;

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
};
/*####*/

modular_arithmetic ma;
int f[1111],c[1111][1111];
int main(){
	scanf("%d%d",&m,&n);
	for(int i=0; i<n; i++)scanf("%s",s[i]);
	for(int j=0; j<m; j++){
		long long int r = 0;
		for(int i=0; i<n; i++)if(s[i][j] == '1')r += 1LL<<i;
		a[r]++;
	}
	f[0]=1;c[0][0]=1;
	for(int i=1; i<=m; i++){
		for(int j=0; j<=i; j++)
			c[i][j] = j==0||j==i?1:ma.add(c[i-1][j],c[i-1][j-1]);
		for(int j=0; j<i; j++)
			f[i] = ma.add(f[i], ma.mul(f[i-1-j], c[i-1][j]));
	}
	int res = 1;
	for(map<long long int,int>::iterator it = a.begin(); it != a.end(); it++)
		res = ma.mul(res, f[it->second]);
	printf("%d\n",res);
	return 0;
}