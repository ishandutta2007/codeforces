#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000


int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int n;
		cin>>n;
		
		vector<int> l(n+1,0),r(n+1,0);
		
		vector<int> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
			r[a[i]]++;
		}
		
		bool f = false;
		for(int i=0;i<n;i++){
			r[a[i]]--;
			for(int j=0;j<=n;j++){
				if(l[j]>0&&r[j]>0){
					f=true;
					break;
				}
			}
			l[a[i]]++;
			if(f)break;
		}
		
		if(f)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
		
	
	return 0;
}