#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000

vector<long long> lucky_numbers;

void Push(long long a){
	if(a>=10000000000)return;
	lucky_numbers.push_back(a);
	Push(a*10+4);
	Push(a*10+7);
}

int main(){
	
	int n;
	cin>>n;
	
	Push(0);
	sort(lucky_numbers.begin(),lucky_numbers.end());
	
	for(int i=0;i<lucky_numbers.size();i++){
		if(lucky_numbers[i]==n){
			cout<<i<<endl;
		}
	}
	
	
	return 0;
}