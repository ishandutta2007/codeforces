#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)



int main(){
	
	string a,b;
	cin>>a>>b;
	int cnt = 0;
	
	int first = 0;
	int last = b.size()-1;
	bool flag = false;
	int num = 0;
	for(int i=0;i<b.size();i++){
		if(a[i]!=b[i])num++;
	}
	if(num%2==0)cnt++;
	int modu = 1000000;
	while(last != a.size()-1){
		
		if(flag==false){
			flag=true;
			for(int i=0;i<b.size();i++){
				if(a[i]!=a[i+1])modu++;
			}
		}
		else{
			if(a[first-1]!=a[first])modu--;
			if(a[last+1]!=a[last])modu++;
		}
		first++;
		last++;
		//cout<<modu<<endl;
		num+=modu;
		num%=2;
		if(num==0)cnt++;
	}
	
	cout<<cnt<<endl;
	
	
	
	return 0;
}