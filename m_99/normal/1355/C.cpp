#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000

int main(){
	
	long long A,B,C,D;
	cin>>A>>B>>C>>D;
	
	int X = B-A;
	int Y = C-B;
	
	if(X>Y)swap(X,Y);
	
	vector<long long> cnt(1200000,0);
	
	for(int i=0;i<cnt.size();i++){
		if(i<=X){
			cnt[i] = i+1;
			continue;
		}
		if(i<=Y){
			cnt[i] = X+1;
			continue;
		}
		int Z = i-X;
		cnt[i] = max(Y-Z+1,0);
	}
	
	for(int i=cnt.size()-2;i>=0;i--)cnt[i] += cnt[i+1];
	
	long long ans = 0;
	for(long long i=C;i<=D;i++){
		long long t = i-A-B+1;
		if(t<0)ans += cnt[0];
		else ans += cnt[t];
		//cout<<ans<<endl;
	}
	cout<<ans<<endl;
	
	return 0;
}