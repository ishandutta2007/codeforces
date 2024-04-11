//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-8;
const int mod=1000000007;
typedef long long ll;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n;
double a[100005];
int b[100005];
bool can[100005];
double myabs(double x){
	return x>0.0?x:-x;
}
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf",&a[i]);
		b[i]=(int)a[i];
		if(myabs(a[i]-b[i])<eps)can[i]=false;
		else can[i]=true;
		if(a[i]<0&&can[i])b[i]--;
//		cerr<<b[i]<<" "<<can[i]<<endl;
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=b[i];
	}
	for(int i=1;i<=n;i++){
		if(sum<0&&can[i])sum++,b[i]++;
	}
	while(sum<0);
	for(int i=1;i<=n;i++)cout<<b[i]<<endl;
	return 0;
}