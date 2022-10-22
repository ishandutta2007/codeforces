#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000



int main(){
	
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		string S;
		cin>>S;
		
		string A="";
		int now = 0;
		while(true){
			if(S[now]<='9'&&S[now]>='0')break;
			A += S[now];
			now++;
		}
		
		int num = 0;
		
		while(true){
			if(now==S.size())break;
			if(S[now]>'9'||S[now]<'0')break;
			num *= 10;
			num +=(int)(S[now] - '0');
			now++;
		}
		if(now==S.size()){
			int ans = 0;
			for(int j=0;j<A.size();j++){
				ans *= 26;
				ans += (int)(A[j]-'A'+1);
			}
			cout<<'R'<<num<<'C'<<ans<<endl;
		}
		else{
			now++;
			int N = 0;
			for(int j=now;j<S.size();j++){
				N*=10;
				N += (int)(S[j]-'0');
			}
			string X = "";

			while(true){
				N--;
				X += (char)('A'+(N%26));
				N/=26;
				if(N==0)break;
			}
			reverse(X.begin(),X.end());
			
			cout<<X<<num<<endl;
			
		}
	}
				
	
	
	return 0;
}