#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000000000000

void print(vector<long long> &h){
	for(int i=0;i<h.size();i++){
		if(i!=0)printf(" ");
		printf("%lld",h[i]);
	}
	cout<<endl;
}

/*
void guchoku(vector<long long> &h){
	
	while(true){
		vector<int> ind;
		for(int i=0;i+1<h.size();i++){
			if(h[i+1]-h[i]>=2){
				ind.push_back(i);
			}
		}
		
		if(ind.size()==0)break;
		for(int i=0;i<ind.size();i++){
			h[ind[i]]++;
			h[ind[i]+1]--;
		}
	}
	
	
	print(h);
}
*/

int main(){
	
	int n;
	cin>>n;
	
	vector<long long> h(n);
	
	for(int i=0;i<n;i++)scanf("%lld",&h[i]);
	long long ok = h[0]-1;
	long long ng = 1000000000003;
	
	while(ng-ok>1){
		long long mid = (ok+ng)/2;
		
		long long sum = 0LL;
		
		for(int i=0;i<n;i++){
			sum += h[i]-(mid+i);
		}

		if(sum<0){
			ng = mid;
		}
		else if(sum>n){
			ok = mid;
		}
		else{
			for(int i=0;i<n;i++){
				h[i] = mid+i;
			}
			
			for(int i=0;i<sum;i++){
				h[i]++;
			}
			
			print(h);
			return 0;
		}
		
		
	}
			
	
	return 0;
}