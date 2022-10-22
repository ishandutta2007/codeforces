#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
vector<int> x;
void Put(int a,int b){
	cout<<a+1<<' '<<b+1<<endl;
}

bool Get(){
	string s;
	cin>>s;
	
	if(s=="Done")return true;
	if(s[0]=='D')x.push_back(1);
	if(s[0]=='U')x.push_back(-1);
	
	return false;
}

int get(int i){
	rep(j,x.size()){
		i += x[j];
	}
	return i;
}

void solve(){
	
	x.resize(0);
	Put(7,7);
	if(Get())return;
	int a = 7,b = 7;
	rep(i,8){
		
		if(b!=0){
			b = 0;
			Put(a,b);
			if(Get())return;
		}
		
		int temp = get(i);
		if(temp<0||temp>=8)continue;
		if(a!=temp){
			a = temp;
			Put(a,b);
			if(Get())return;
		}
		while(b!=7){
			temp = get(i);
			if(temp<0||temp>=8)break;
			a = temp,b++;
			Put(a,b);
			if(Get())return;
		}	
		
	}

	
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		solve();
		
		
	}
			
	return 0;
}