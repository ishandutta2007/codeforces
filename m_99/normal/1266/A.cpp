#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000



int main(){
	
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		
		int sum = 0;
		int cnt_0 = 0;
		int cnt_2 = 0;
		for(int j=0;j<s.size();j++){
			int num = s[j] - '0';
			sum += num;
			if(num==0)cnt_0 ++;
			if(num%2==0)cnt_2 ++;
		}
		if(sum%3!=0){
			cout<<"cyan"<<endl;
			continue;
		}
		if(cnt_0==0){
			cout<<"cyan"<<endl;
			continue;
		}
		cnt_2--;
		if(cnt_2<=0){
			cout<<"cyan"<<endl;
			continue;
		}
		cout<<"red"<<endl;
	}
	
	return 0;
}