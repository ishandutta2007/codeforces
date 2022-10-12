#include<cstdio>
#include<cstring>

/*#### modular_arithmetic */
class modular_arithmetic{
public:
	int mod, range;

	modular_arithmetic(){
		mod = 998244353;
	}
	//No specific settings.
	int add(int x,int y){return (x+=y)<mod?x:x-mod;}
	int sub(int x,int y){return (x-=y)>=0?x:x+mod;}
	int mul(int x,int y){return (int)((long long int)x*y%mod);}
	int pw(int base, int p) {
		int res = 1, mu = base%mod;
		for(;p>0;p/=2) {
			if (p&1) res = mul(res, mu);
			mu = mul(mu, mu);
		}
		return res;
	}
	int rev(int x) {return pw(x, mod-2);}
};
/*####*/
modular_arithmetic ma;

const int R = 3666;
int row,col;
bool bad_row[R], bad_col[R];
int c[R][R],fac[R];
int d1[R][R], d2[R][R];
int dp[R][R];
void proc(int n,bool g[R], int d[R][R]){
	memset(dp,0,sizeof(dp));
	dp[0][0] = 1;
	for(int i=0; i<n; i++)
		for(int j=0; j<=i; j++)if(dp[i][j]){
			dp[i+1][j] = ma.add(dp[i+1][j], dp[i][j]);
			if(i<n-1 && !g[i] && !g[i+1])
				dp[i+2][j+1] = ma.add(dp[i+2][j+1], dp[i][j]);
		}
	int cnt = 0;
	for(int i=0; i<n; i++)if(!g[i])cnt++;
	for(int j=0; j<=n; j++)if(dp[n][j]){
		int w = cnt - j * 2;
		for(int k=0; k<=w; k++)
			d[j][k] = ma.mul(c[w][k], dp[n][j]);
	}
}
int main(){
	int n,x,y;
	scanf("%d%d%d",&row,&col,&n);
	for(int i=0; i<n*2; i++){
		scanf("%d%d",&x,&y);
		bad_row[x-1] = true;
		bad_col[y-1] = true;
	}
	fac[0] = 1;
	for (int i = 1; i < R; i++)fac[i] = ma.mul(fac[i - 1], i);
	for(int i=0; i<R; i++)
		for(int j=0; j<=i; j++)
			c[i][j] = j==0||j==i?1:ma.add(c[i-1][j],c[i-1][j-1]);
	proc(row, bad_row, d1);
	proc(col, bad_col, d2);
	int res = 0;
	for(int i=0; i<=row || i<=col; i++)for(int j=0; j<=row || j<=col; j++)
		if(d1[i][j] != 0 && d2[j][i] != 0)
			res = ma.add(res,ma.mul(ma.mul(d1[i][j],d2[j][i]),ma.mul(fac[i], fac[j])));
	printf("%d\n",res);
	return 0;
}