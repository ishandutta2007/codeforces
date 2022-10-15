#include <bits/stdc++.h>
using namespace std;
void solve(){
	long long N,M,K;
	cin>>N>>M>>K;
	long long arr[N];
	for(long long i=0;i<N;i++)cin>>arr[i];
	sort(arr,arr+N);
	long long p=M/(K+1);
	long long a=p*K*arr[N-1];
	long long b=p*arr[N-2];
	long long c=M%(K+1);
	c*=arr[N-1];
	cout<<(long long)a+b+c<<"\n";
}
int main(){
	int T=1;
	//cin>>T;
	while(T--)solve();
	return 0;
}