#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n,m;
		cin>>n>>m;
		string s;
		cin>>s;
		vector<int> S(n+1,0);
		rep(i,n){
			S[i+1] = s[i]-'0';
			S[i+1] += S[i];
		}
		
		long long c1 = S.back();
		c1 *= m;
		if(c1%n!=0){
			cout<<-1<<endl;
			continue;
		}
		c1 /= n;
		bool f = false;
		rep(i,n+1){
			if(i+1 - m >= 0 && i+1<=n &&  S[i+1] - S[i+1-m] == c1){
				cout<<1<<endl;
				cout<<i+2-m<<' '<<i+1<<endl;
				f = true;
				break;
			}
		}
		if(f)continue;
		m = n-m;
		c1 = S.back() - c1;
		rep(i,n+1){
			if(i+1 - m >= 0 && i+1<=n && S[i+1] - S[i+1-m] == c1){
				cout<<2<<endl;
				cout<<1<<' '<<i+1-m<<endl;
				cout<<i+2<<' '<<n<<endl;
				f = true;
				break;
			}
		}
		if(f)continue;
		cout<<-1<<endl;
	}
	
	return 0;
}