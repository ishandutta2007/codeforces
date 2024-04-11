#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000



int main(){
	
	string s,t;
	cin>>s>>t;
	
	int correct_pos = 0;
	
	for(int i=0;i<s.size();i++){
		if(s[i]=='+')correct_pos++;
		else correct_pos--;
	}
	
	int wrong_pos = 0;
	int Q_cnt = 0;
	
	for(int i=0;i<t.size();i++){
		if(t[i]=='+')wrong_pos++;
		else if(t[i]=='-')wrong_pos--;
		else Q_cnt ++;
	}
	
	int cnt = 0;
	
	if(Q_cnt!=0){
		for(int i=0;i<(1<<Q_cnt);i++){
			int now = wrong_pos;
			for(int j=0;j<Q_cnt;j++){
				if(((1<<j)&i)!=0)now++;
				else now--;
			}
			if(now==correct_pos)cnt++;
		}
		cout<<fixed<<setprecision(15)<<(double)cnt / (1<<Q_cnt)<<endl;
	}
	else{
		if(correct_pos==wrong_pos){
			cout<<1<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
	
	return 0;
}