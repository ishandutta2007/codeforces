#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000

int main(){
	
	int n;
	cin>>n;
	
	vector<int> a(n);
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	int x,y;
	cin>>x>>y;
	
	
	x--;
	y-=2;
	
	int maxi = -1;
	int ans = 0;
	int sum = 0;
	
	for(int i=0;i<n;i++){
		if(i==0){
			for(int j=x;j<=y;j++)sum += a[j];
		}
		else{
		}
		if(maxi<sum){
			maxi = sum;
			ans = i;
		}

		sum -= a[y];
		x--;
		y--;
		if(x<0)x+=n;
		if(y<0)y+=n;
		sum += a[x];
	}
	
	cout<<ans+1<<endl;
	
	return 0;
}