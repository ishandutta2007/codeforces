#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000



int main(){
	
	int N;
	cin>>N;
	
	vector<int> P;
	for(int i=2;i<=N;i++){
		bool f = true;
		for(int j=2;j<i;j++){
			if(i%j==0){
				f=false;
				break;
			}
		}
		if(f){
			int x = i;
			
			while(x<=N){
				P.push_back(x);
				x*=i;
			}
		}
	}
	
	cout<<P.size()<<endl;
	rep(i,P.size()){
		if(i!=0)cout<<' ';
		cout<<P[i];
	}
	cout<<endl;
	
    return 0;
}