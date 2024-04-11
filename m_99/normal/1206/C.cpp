#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000


int main(){

	int N;
	cin>>N;
	if(N%2==0){
		cout<<"NO"<<endl;
		return 0;
	}
	
	vector<int> ans(2*N);
	
	for(int i=0;i<N;i++){
		int a = i*2;
		int b = i*2+1;
		a++;b++;
		
		if(i%2==0){
			ans[i] = a;
			ans[i+N] = b;
		}
		else{
			ans[i] = b;
			ans[i+N] = a;
		}
	}
	cout<<"YES"<<endl;
	for(int i=0;i<2*N;i++){
		if(i!=0)cout<<' ';
		cout<<ans[i];
	}
	
	cout<<endl;
		
		
	return 0;
}