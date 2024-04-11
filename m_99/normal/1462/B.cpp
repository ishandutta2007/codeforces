#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000


int main(){
	
	int _t;
	cin>>_t;
	
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		
		string s;
		cin>>s;
		bool f = false;
		for(int i=0;i<=4;i++){
			string t = s.substr(0,i);
			t += s.substr(s.size()-(4-i));
			if(t=="2020"){
				f=true;
				break;
			}
		}
		if(f)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
	
	
    return 0;
}