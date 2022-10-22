#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000

int main(){
	
	long long N,K;
	cin>>N>>K;
	
	vector<long long> a(K);
	for(int i=0;i<K;i++)cin>>a[i];
	
	long long mini = 1000000000000000001;
	int ind = 0;
	
	for(int i=0;i<K;i++){
		if(mini>N%a[i]){
			ind = i;
			mini = N%a[i];
		}
	}
	
	cout<<ind+1<<' '<<N/a[ind]<<endl;
	
	
	return 0;
}