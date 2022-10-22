#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
ll a[maxn],ans;
int b[maxn],n;
struct custom_hash{
    static uint64_t splitmix64(uint64_t x){
        x+=0x9e3779b97f4a7c15;
        x=(x^(x>>30))*0xbf58476d1ce4e5b9;
        x=(x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31);
    }
    inline size_t operator()(uint64_t x)const{
        static const uint64_t FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x+FIXED_RANDOM);
    }
};
unordered_map<ll,int,custom_hash>cnt;
set<ll>s;
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%lld",a+i),++cnt[a[i]];
	for(ri i=1;i<=n;++i){
		scanf("%d",b+i);
		if(cnt[a[i]]>=2)s.insert(a[i]);
	}
	for(ri i=1;i<=n;++i){
		bool flag=false;
		for(ll j:s)
			if((j&a[i])==a[i])
				flag=true;
		if(flag)ans+=b[i];
	}
	printf("%lld",ans);
	return 0;
}