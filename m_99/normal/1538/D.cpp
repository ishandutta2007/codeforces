#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
vector<int> ps;
vector<bool> isp(40000,true);

int f(int a){
	int ret = 0;
	rep(i,ps.size()){
		while(a%ps[i]==0){
			ret++;
			a/=ps[i];
		}
	}
	if(a!=1)ret++;
	return ret;
}

int main(){
	
	
	for(int i=2;i<isp.size();i++){
		if(isp[i]){
			ps.push_back(i);
			for(int j=i;j<isp.size();j+=i)isp[j] = false;
		}
	}
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int a,b,k;
		scanf("%d %d %d",&a,&b,&k);
		
		if(k==1){
			if(a!=b&&(a%b==0||b%a==0)){
				cout<<"YES"<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
		}
		else{
			if(k <= f(a)+f(b))cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	return 0;
}