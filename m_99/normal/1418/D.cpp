#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 100000000

int main(){
	
	int n,q;
	cin>>n>>q;
	
	set<int> S;
	multiset<int> D;
	
	vector<int> p(n);
	rep(i,n){
		scanf("%d",&p[i]);
	}
	
	sort(p.begin(),p.end());
	
	rep(i,n){
		S.insert(p[i]);
		if(i!=0){
			D.insert(p[i]-p[i-1]);
		}
	}
	
	rep(i,q+1){
		int ans = 0;
		if(S.size()>1){
			ans = (*S.rbegin()) - (*S.begin());
			ans -= (*D.rbegin());
		}
		printf("%d\n",ans);
		if(i==q)break;
		int t,x;
		scanf("%d %d",&t,&x);
		if(t==0){
			auto it = S.upper_bound(x);
			if(it!=S.end()){
				D.erase(D.lower_bound((*it)-x));
			}
			it = S.lower_bound(x);
			if(it!=S.begin()){
				it--;
				D.erase(D.lower_bound(x-(*it)));
			}
			it = S.lower_bound(x);
			it = S.erase(it);
			if(it!=S.end()&&it!=S.begin()){
				int d = *it;
				it--;
				d -= *it;
				D.insert(d);
			}
		}
		else{
			auto it = S.upper_bound(x);
			if(it!=S.end()&&it!=S.begin()){
				int d = *it;
				it--;
				d -= *it;
				D.erase(D.lower_bound(d));
			}
			S.insert(x);
			it = S.upper_bound(x);
			if(it!=S.end()){
				D.insert((*it)-x);
			}
			it = S.lower_bound(x);
			if(it!=S.begin()){
				it--;
				D.insert(x-(*it));
			}
		}
	}
	
    return 0;
}