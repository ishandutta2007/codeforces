#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n;
double p[32][32];
double dp[1<<18];
bool vis[1<<18];

double f(int m){
	if(vis[m])return dp[m];
	vis[m]=true;
	double r;
	if(!(m&1))r=0.;
	else if(m==1)r=1.;
	else {
		r=0.;
		fore(i,0,n)if(m&(1<<i))fore(j,i+1,n)if(m&(1<<j)){
			r=max(r,p[i][j]*f(m^(1<<j))+p[j][i]*f(m^(1<<i)));
		}
	}
	return dp[m]=r;
}

int main(){
	scanf("%d",&n);
	fore(i,0,n)fore(j,0,n)scanf("%lf",&p[i][j]);
	printf("%.12lf\n",f((1<<n)-1));
	return 0;
}