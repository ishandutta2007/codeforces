/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#pragma optimize("Ofast")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n;
int a[100005],b[100005];
inline int gcd(int x,int y){
	while(x&&y){
		if(x>y)x%=y;
		else y%=x;
	}
	return x+y;
}
void print(int orz){
	puts("YES");
	multiset<int>F;
	for(int i=0;i<=orz;i++)F.insert(b[i]);
	for(int i=0;i<n;i++){
		if(F.count(a[i])){
			F.erase(F.find(a[i]));
			printf("1 ");
		}else{
			printf("2 ");
		}
	}
}
int main(){
	srand(19260817);
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]),b[i]=a[i];
	while(clock()<=460){
		register int now=0,now2=0,i,j;
		for(i=0;i<n;i++){
			now=gcd(now,b[i]);
//			cerr<<b[i]<<" "<<now<<endl;
			if(now==1)break;
		}j=i;
		if(now==1){
			for(i++;i<n;i++)now2=gcd(now2,b[i]);
//			for(i=0;i<n;i++)cerr<<b[i]<<" ";
//			cerr<<endl<<" "<<now<<" "<<now2<<" "<<j<<endl;
			if(now2==1){
				print(j);
				return 0;
			}
		}
		random_shuffle(b,b+n);
	}
	puts("NO");
	return 0;
}