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
		scanf("%d",&n);
		set<int> unusedA,unusedB;
		rep(i,n){
			unusedA.emplace_hint(unusedA.end(),i+1);
			unusedB.emplace_hint(unusedB.end(),i+1);
		}
		vector<int> q(n);
		rep(i,n){
			scanf("%d",&q[i]);
			unusedA.erase(q[i]);
			unusedB.erase(q[i]);
		}
	//	cout<<unusedA.size()<<','<<unusedB.size()<<endl;
		vector<int> pA(n),pB(n);
		
		rep(i,n){
			if(i==0 || q[i]!=q[i-1]){
				pA[i] = q[i];
				pB[i] = q[i];
			}
			else{
				auto itA = unusedA.begin();
				auto itB = unusedB.upper_bound(q[i]);
				itB--;
				pA[i] = *itA;
				pB[i] = *itB;
				unusedA.erase(itA);
				unusedB.erase(itB);
			}
		}
		
		rep(i,n){
			if(i!=0)printf(" ");
			printf("%d",pA[i]);
		}
		printf("\n");
		rep(i,n){
			if(i!=0)printf(" ");
			printf("%d",pB[i]);
		}
		printf("\n");
	}

    return 0;
}