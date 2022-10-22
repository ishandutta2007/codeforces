#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000


int main(){
	
	vector<long long> cnt(20,0);
	int N;
	cin>>N;
	
	for(int i=0;i<N;i++){
		int a;
		scanf("%d",&a);
		for(int j=0;j<20;j++){
			if((a>>j)&1)cnt[j]++;
		}
	}
	
	long long ans = 0;
	for(int i=0;i<N;i++){
		long long t = 0;
		for(int j=0;j<20;j++){
			if(cnt[j]>0){
				t |= (1<<j);
				cnt[j]--;
			}
		}
		ans += t*t;
	}
	
	cout<<ans<<endl;
	
	return 0;
}