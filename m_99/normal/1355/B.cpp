#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000

int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int N;
		priority_queue<int,vector<int>,greater<int>> Q;
		scanf("%d",&N);
		for(int i=0;i<N;i++){
			int e;
			scanf("%d",&e);
			Q.push(e);
		}
		
		int ans = 0;
		while(Q.size()!=0){
			int k = Q.top();
			//cout<<k<<endl;
			for(int i=0;i<k;i++){
				k = max(k,Q.top());
				Q.pop();
				if(i==k-1){
					ans++;
					break;
				}
				if(Q.size()==0)break;
			}

		}
		printf("%d\n",ans);
	}
	
	return 0;
}