#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}


signed main(){
	int a,b;
	scanf("%lld%lld",&a,&b);
	
	if(a<b){
		puts("-1");
		return 0;
	}
	if(a==b){
		printf("%.20Lf\n",1.0L*b);
		return 0;
	}

	int k1=(a-b)/(2*b);
	int k2=(a+b)/(2*b)-1;

	long double x=(a+b)/2;
	if(k1)chmin(x,1.0L*(a-b)/(2*k1));
	if(k2)chmin(x,1.0L*(a+b)/2/(k2+1));
	printf("%.20Lf\n",x);
	return 0;
}