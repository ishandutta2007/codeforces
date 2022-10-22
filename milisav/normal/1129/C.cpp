#include<bits/stdc++.h>
using namespace std;
long long n;
long long vl;
long long a[4000];
long long dp[3001][3001];
long long mod=1000000007;
long long bd;
long long md;
vector<pair<long long,int> > srt[3001];
long long res[3001];
int main() {
    scanf("%lld",&n);
    long long hs;
    bool tk;
    md=1;
    bd=1;
    for(int i=0;i<18;i++) md*=10;
    for(int i=0;i<12;i++) bd*=10;
    md+=7;
    bd+=7;
    for(long long i=0;i<n;i++) {
        scanf("%lld",&vl);
        a[i]=vl;
        long long c=1;
        hs=0;
        for(long long j=i;j>=0;j--) {
            hs=(hs+(c*(a[j]+1ll)))%md;
            c=(c*bd)%md;
            for(long long k=0;k<4 && k<=i-j;k++) {
                tk=true;
                if(k==3) {
                    if(a[i]==1 && a[i-1]==1 && a[i-2]==1 && a[i-3]==1) tk=false;
                    if(a[i]==0 && a[i-1]==1 && a[i-2]==1 && a[i-3]==1) tk=false;
                    if(a[i]==1 && a[i-1]==0 && a[i-2]==1 && a[i-3]==0) tk=false;
                    if(a[i]==1 && a[i-1]==1 && a[i-2]==0 && a[i-3]==0) tk=false;
                }
                if(tk) {
                    if(i-k==j) dp[j][i]=(dp[j][i]+1)%mod;
                    else {
                        dp[j][i]=(dp[j][i]+dp[j][i-k-1])%mod;
                    }
                }
            }
            srt[i-j].push_back(make_pair(hs,i));
        }
    }
    for(int k=0;k<n;k++) {
    	sort(srt[k].begin(),srt[k].end());
    	for(int i=0;i<srt[k].size();i++) {
    		if(i==0 || srt[k][i].first!=srt[k][i-1].first) {
    			//cout<<srt[k][i].second-k<<" "<<srt[k][i].second<<endl;
				res[srt[k][i].second]=(res[srt[k][i].second]+dp[srt[k][i].second-k][srt[k][i].second])%mod;
			}
    	}
    }
    for(int i=0;i<n;i++) {
		printf("%d\n",res[i]);
		res[i+1]=(res[i+1]+res[i])%mod;
	}
    return 0;
}