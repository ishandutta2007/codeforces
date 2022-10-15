#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
//#define int long long
using namespace __gnu_pbds;
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int n,k,a[3010],cnt[3010];
long long sum[3010];

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+1ll*a[i];
		cnt[i]=cnt[i-1]+(a[i]==0);
	}
	if(sum[n]>1ll*cnt[n]*k||sum[n]<-1ll*cnt[n]*k){
		cout<<-1<<'\n';
		return 0;
	}
	long long ans=0ll;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int num=cnt[j]-cnt[i-1];long long val=sum[j]-sum[i-1];
			long long L=max(-1ll*num*k,-sum[n]-1ll*(cnt[n]-num)*k);
			long long R=min(1ll*num*k,-sum[n]+1ll*(cnt[n]-num)*k);
			ans=max(ans,abs(val+L));ans=max(ans,abs(val+R));
		}
	}
	cout<<ans+1ll<<'\n';
	return 0;
}