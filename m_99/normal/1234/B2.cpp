#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	
	int _t;
	//cin>>_t;
	_t = 1;
	rep(_,_t){
		
		int n,k;
		cin>>n>>k;
		
		vector<int> id(n);
		rep(i,n)scanf("%d",&id[i]);
		set<int> S;
		deque<int> D;
		rep(i,n){
			if(S.count(id[i]))continue;
			if(D.size()==k){
				S.erase(D.back());
				D.pop_back();
			}
			D.push_front(id[i]);
			S.insert(id[i]);
		}
		
		printf("%d\n",D.size());
		rep(i,D.size()){
			if(i!=0)printf(" ");
			printf("%d",D[i]);
		}
		cout<<endl;
	}
	
	return 0;
}