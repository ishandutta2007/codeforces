#include <bits/stdc++.h>
using namespace std;
#define modulo m
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000


int main(){
	
	int n,m,p;
	cin>>n>>m>>p;
	
	
	
	vector<int> a(n),b(m);
	
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	for(int i=0;i<m;i++){
		scanf("%d",&b[i]);
	}
	
	mt19937 engine(chrono::steady_clock::now().time_since_epoch().count());
	
	int x = 0;
	
	vector<int> aa;
	
	for(int i=0;i<n;i++){
		if(a[i]%p!=0){
			aa.push_back(i);
		}
	}
	
	vector<int> bb;
	
	for(int i=0;i<m;i++){
		if(b[i]%p!=0){
			bb.push_back(i);
		}
	}
	
	shuffle(bb.begin(),bb.end(),engine);
	

	for(int ii=0;ii<bb.size();ii++){
		for(int jj=0;jj<aa.size();jj++){
			int k = aa[jj]+bb[ii];
			int sum = 0;
			for(int i=0;i<=k;i++){
				int ii = i;
				int jj = k-ii;
				if(ii>=n||jj>=m)continue;
				sum += ((long long)a[ii]*b[jj])%p;
				sum%=p;
				
			}
			
			if(sum%p!=0){
				cout<<k<<endl;
				return 0;
			}
		}
	}
	
	return 0;
}