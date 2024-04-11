#include<cstdio>
#include<algorithm>
#include<cstring>
#include<random>
#include<chrono>
#include<unordered_map>
using namespace std;
typedef long long ll;
const int MAXN=1e6+5;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
inline ll rndll(){
	return (ll)(rnd())<<32|rnd();
}
int n;
bool nop[MAXN];
ll f[MAXN],_n;
unordered_map<ll,int> mp;
int ans,a1,a2,a3;
int main(){
	scanf("%d",&n);
	for(int i=2; i<=n; i++)
		if(!nop[i]){
			f[i]=rndll();
			for(int j=i+i; j<=n; j+=i){
				nop[j]=1;
				int x=j/i;
				f[j]^=f[i];
				while(x%i==0) 
					x/=i,f[j]^=f[i];
			}
		}
	for(int i=1; i<=n; i++)
		f[i]^=f[i-1],_n^=f[i];
	if(n&1){
		ans=2;
		a1=n;
		a2=n-1>>1;
		if(n-1>>1&1) ans++,a3=2;
	}else{
		ans=1;
		a1=n>>1;
		if(n>>1&1) ans++,a2=2;
	}
	if(!_n) ans=0;
	for(int i=2; i<=n; i++)
		if(f[i]==_n&&ans>1){
			ans=1;
			a1=i;
		}
	if(ans==3){
		for(int i=2; i<=n; i++){
			auto it=mp.find(f[i]^_n);
			if(it!=mp.end()){
				ans=2;
				a1=it->second;
				a2=i;
				break;
			}
			mp[f[i]]=i;
		}
	}
	printf("%d\n",n-ans);
	for(int i=1; i<=n; i++){
		if(ans>=1&&a1==i) continue;
		if(ans>=2&&a2==i) continue;
		if(ans>=3&&a3==i) continue;
		printf("%d ",i);
	}
	puts("");
	return 0;
}