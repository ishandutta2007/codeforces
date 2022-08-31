#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)

using namespace std;

int cnt[1010];

int main(){
	int n;cin>>n;
	REP(i,n-1){
		int a,b;
		cin>>a>>b;
		cnt[a-1]++;
		cnt[b-1]++;
	}
	int ans=0;
	REP(i,n)if(cnt[i]==1)
		ans++;
	cout<<ans<<endl;
}