#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)

long long kiriage(int a){
	if(a>=0)return (long long)a+1;
	else return (long long)a;
}

long long kirisute(int a){
	if(a>=0)return (long long)a;
	else return (long long)a-1;
}

int main(){
	
	int n;
	cin>>n;
	
	vector<double> a(n);
	long long cnt = 0;
	vector<int> b(n,modulo);
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(abs(a[i]-ceil(a[i]))<0.000001){
			b[i] = ceil(a[i]);
			cnt = cnt + (long long)b[i];
		}
		else{
			cnt =cnt+(long long)ceil(a[i]);
		}
	}
	for(int i=0;i<n;i++){
		if(b[i]!=modulo)continue;
		if(cnt>0){
			cnt--;
			b[i] = floor(a[i]);
		
		}
		else{
			b[i] = ceil(a[i]);
			
		}
	}
	
	for(int i=0;i<n;i++){
		cout<<b[i]<<endl;
	}
		
	
	
	return 0;
}