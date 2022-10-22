#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	
	
	rep(_,_t){
		
		int n,k;
		cin>>n>>k;
		
		string s = to_string(n);
		vector<bool> b(10,false);
		rep(i,k)b[i] = true;
		sort(b.begin(),b.end());
		string ans(s.size(),'9');
		do{
			rep(k,s.size()+1){
				int state = 0;
				string temp = "";
				rep(i,s.size()){
					int t = s[i]-'0';
					if(i<k){
						if(b[t]==false){
							state = -1;
							break;
						}
						temp += t+'0';
					}
					else if(i==k){
						state = -1;
						for(int j=t+1;j<10;j++){
							if(b[j]){
								temp += '0'+j;
								state = 1;
								break;
							}
						}
						if(state==-1)break;
					}
					else{
						rep(j,10){
							if(b[j]){
								temp += '0'+j;
								break;
							}
						}
						
					}
					
				}
				if(state!=-1){
					ans = min(ans,temp);
				}
			}
			
		}
		while(next_permutation(b.begin(),b.end()));
		cout<<ans<<endl;
	}
	
	return 0;
}