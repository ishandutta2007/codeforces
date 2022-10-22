#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 1000000000000


int main() {

	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int n,k;
		cin>>n>>k;
		k--;
		string S(n,'a');
		S.back() = 'b';
		S[S.size()-2] = 'b';
		
		int now = S.size()-2;
		
		for(int i=1;true;i++){
			if(k>=i){
				k-=i;
				swap(S[now],S[now-1]);
				now--;
			}
			else{
				break;
			}
		}
		now = S.size()-1;
		for(int i=0;i<k;i++){
			swap(S[now],S[now-1]);
			now--;
		}
		cout<<S<<endl;
	}

    return 0;
}