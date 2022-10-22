#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long k[10000];
bool comp[10000];
long long q=5000;
vector<long long> pr;
long long cnt[6000][1000];
long long l=n/2;
long long tots,ans;
bool ers[10000];
long long count(long long j,long long v) {
	long long rt=0;
	for(long long i=0;i<=q;i++) {
		if(cnt[i][j]>=v) rt+=k[i];
	}
	return rt;
}
long long er(long long j,long long v) {
	long long rt=0;
	for(long long i=0;i<=q;i++) {
		if(cnt[i][j]>=v) {
			rt-=k[i]*v;
		}
		else {
			rt+=k[i]*(v-2*cnt[i][j]);	
		}
		if(cnt[i][j]!=v && !ers[i]) {
			ers[i]=true;
			for(long long t=0;t<pr.size();t++) cnt[i][t]=0;
		}
	}
	return rt;
}
int main() {
	for(long long i=2;i<=q;i++) {
		if(!comp[i]) {
			pr.push_back(i);
			for(long long j=i*i;j<=q;j+=i) comp[j]=true; 
		}
	}
	m=pr.size();
	for(long long t=2;t<=q;t++) {
		long long g=t;
		for(long long i=0;i<m;i++) {
			cnt[t][i]=cnt[t-1][i];
			while(g%pr[i]==0) {
				g/=pr[i];
				cnt[t][i]++;
			}
		}
	}
	scanf("%lld",&n);
	for(long long i=0;i<n;i++) {
		long long t;
		scanf("%lld",&t);
		k[t]++;
	}
	long long h=n/2;
	for(long long i=1;i<=q;i++) {
		for(long long j=0;j<m;j++) {
			tots+=k[i]*cnt[i][j];
		}
	}
	ans=tots;
	//cout<<tots<<endl;
	for(long long j=m-1;j>=0;j--) {
		long long l=0,r=0;
		for(int i=1;i<=q;i++) r=max(r,cnt[i][j]);
		r+=1;
		while(l<r) {
			long long mid=(l+r+1ll)>>1ll;
			if(count(j,mid)>h) l=mid;
			else r=mid-1;
		}
		long long t=er(j,l);
		tots+=t;
		//cout<<pr[j]<<" "<<l<<" "<<t<<endl;
		ans=min(ans,tots);
	}
	printf("%lld",ans);
	return 0;
}