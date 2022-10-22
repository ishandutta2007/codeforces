#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 2000000000000000001



int main(){
	
	int _t;
	cin>>_t;
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<vector<int>> p(1);
		rep(i,n){
			int a;
		scanf("%d",&a);	
		a--;
			p[0].push_back(a);
		}
		
		long long ans = 0;
		while(p.size()>0){
			vector<int> cur = p.back();
			p.pop_back();
			if(cur.size()==1)continue;
			
			int m = cur.size()/2;
		//	cout<<m<<endl;
			vector<int> x,y;
			rep(i,m*2){
				if(i<m)x.push_back(cur[i]);
				else y.push_back(cur[i]);
			}
			if(x[0]>y[0]){
				ans++;
				swap(x,y);
			}
			//cout<<ans<<endl;
			//rep(i,m)cout<<x[i]<<',';
			//cout<<endl;
			bool f = true;
			rep(i,x.size()){
				//cout<<i<<endl;
				if(x[i] >= m){
					f = false;
					break;
				}
				if(y[i]<m){
					f = false;
					break;
				}
				else y[i] -= m;
			}
			if(!f){
				ans = -1;
				break;
			}
			p.push_back(x);
			p.push_back(y);
			
			
		}
		printf("%d\n",ans);
		
	}
	
	return 0;
}