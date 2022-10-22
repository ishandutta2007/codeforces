#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	int n;
	scanf("%d",&n);
	vector<int> a(n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	vector<long long> p;
	
	for(int i=0;i<2;i++){
		int t = a[i];
		
		for(int j=2;t!=1;j++){
			if(t%j==0){
				p.push_back(j);
				while(t%j==0){
					t/=j;
				}
			}
		}
	}
	
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	
	long long ans = 1;
	
	for(int i=0;i<p.size();i++){
		
		vector<int> V;
		for(int j=0;j<n;j++){
			int t = a[j];
			int c = 0;
			while(t%p[i]==0){
				c++;
				t/=p[i];
			}
			V.push_back(c);
		}
	
		sort(V.begin(),V.end());
		for(int j=0;j<V[1];j++){
			ans *= p[i];
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}