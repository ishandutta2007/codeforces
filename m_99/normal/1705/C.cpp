#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n,c,q;
		cin>>n>>c>>q;
		
		string S;
		cin>>S;
		
		vector<long long> l(c),r(c);
		vector<long long> t;
		t.push_back(n);
		rep(i,c){
			cin>>l[i]>>r[i];
			l[i]--;
			t.push_back(t.back() + r[i] - l[i]);
		}
		t.push_back(1e18);
		long long k = -1;
		rep(__,q){
			if(k==-1){
				cin >>k;
				k--;
			}
			if(k<n){
				cout<<S[k]<<endl;
				k = -1;
				continue;
			}
			rep(i,c){
				if(t[i]<=k && k<t[i+1]){
					//cout<<t[i]<<','<<l[i]<<','<<(k-t[i])<<endl;
					k = l[i] + (k-t[i]);
					//cout<<k<<endl;
					__--;
					break;
				}
			}
		}
		
	}
	
	
    return 0;
}