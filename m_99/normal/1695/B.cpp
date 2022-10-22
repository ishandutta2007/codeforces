#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		vector<long long> a(n);
		rep(i,n)cin>>a[i];
		if(n%2==1){
			cout<<"Mike"<<endl;
			continue;
		}
		bool f = false;
		
		rep(i,n){
			if(i!=0)continue;
			long long m = Inf;
			rep(j,n)m = min(m,a[j]);
			long long t = m * n;
			auto b = a;
			rep(j,n){
				b[j] -= m;
			}
			int cur = i;
			while(true){
				if(b[cur]==0)break;
				b[cur]--;
				t++;
				cur ++;
				cur %= n;
			}
			if(t%2==1){
				f = true;
				break;
			}
			
		}
		
		if(f)cout<<"Mike"<<endl;
		else cout<<"Joe"<<endl;
		
	}
	
    return 0;
}