#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000


int main(){
	
	int n;
	string s;
	cin>>n>>s;
	
	int now = 0;
	bool F = false;
	
	for(int i=0;i<n;i++){
		if(s[i]=='(')now++;
		else now--;
		
		if(now==-1){
			if(!F){
				F=true;
				now=0;
			}
			else{
				cout<<"No"<<endl;
				return 0;
			}
		}
	}
	
	if(F){
		if(now==1){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
	else{
		if(now==0){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
	
	
	return 0;
}