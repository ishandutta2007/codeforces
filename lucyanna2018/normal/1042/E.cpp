#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;

#define i64 long long int
// #define i128 __int128_t

struct modular_arithmetic{
	int mod;

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
modular_arithmetic ma;

int row,col;
int a[1010][1010];
int n;
pair<int,pair<int,int> > b[1010*1010];
int d[1010 * 1010];
int main(){
	scanf("%d%d",&row,&col);
	for(int i=1; i<=row; i++)for(int j=1; j<=col; j++){
		scanf("%d",&a[i][j]);
	}
	int X,Y;
	scanf("%d%d",&X,&Y);
	for(int i=1; i<=row; i++)for(int j=1; j<=col; j++){
		if(a[i][j] < a[X][Y])
			b[n++]=make_pair(a[i][j],make_pair(i,j));
	}
	b[n++] = make_pair(a[X][Y],make_pair(X,Y));
	sort(b,b+n);
	int all = 0;
	int x = 0, y = 0, x2 = 0, y2 = 0;
	for(int i=0,j; i<n; i=j){
		int iv = ma.rev(i);
		for(j=i; j<n && b[j].first == b[i].first; j++){
			if(i == 0){d[j] = 0;continue;}
			int res = all, xx = b[j].second.first, yy = b[j].second.second;
			res = ma.add(res, ma.mul(ma.mul(xx, xx), i));
			res = ma.add(res, ma.mul(ma.mul(yy, yy), i));
			res = ma.add(res, x2);
			res = ma.add(res, y2);
			res = ma.sub(res, ma.mul(ma.mul(2, xx), x));
			res = ma.sub(res, ma.mul(ma.mul(2, yy), y));
			d[j] = ma.mul(res, iv);
		}
		for(j=i; j<n && b[j].first == b[i].first; j++){
			all = ma.add(all, d[j]);
			int xx = b[j].second.first, yy = b[j].second.second;
			x = ma.add(x, xx);
			y = ma.add(y, yy);
			x2 = ma.add(x2, ma.mul(xx, xx));
			y2 = ma.add(y2, ma.mul(yy, yy));
		}
	}
	printf("%d\n",d[n-1]);
	return 0;
}