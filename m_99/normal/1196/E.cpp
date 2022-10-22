#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int b,w;
		scanf("%d %d",&b,&w);
		swap(b,w);
		vector<int> x(1,10),y(1,10);
		x.push_back(11);
		y.push_back(10);
		b--;w--;
		while(b>0&&w>0){
			rep(i,2){
				x.push_back(x.back()+1);
				y.push_back(y.back());
			}
			b--;w--;
		}
		
		if(max(b,w) > (x.size())+1){
			printf("NO\n");
			continue;
		}
		
		if(w>0){
			w--;
			x.push_back(9);
			y.push_back(10);
			rep(i,x.size()){
				if(y[i]!=10)continue;
				if(x[i]%2==1)continue;
				if(w){
					x.push_back(x[i]);
					y.push_back(y[i]-1);
					w--;
				}
				if(w){
					x.push_back(x[i]);
					y.push_back(y[i]+1);
					w--;
				}
			}
					
		}
		else if(b>0){
			b--;
			x.push_back(x.back()+1);
			y.push_back(10);
			rep(i,x.size()){
				if(y[i]!=10)continue;
				if(x[i]%2==0)continue;
				if(b){
					x.push_back(x[i]);
					y.push_back(y[i]-1);
					b--;
				}
				if(b){
					x.push_back(x[i]);
					y.push_back(y[i]+1);
					b--;
				}
			}
		}
		
		printf("YES\n");
		rep(i,x.size()){
			printf("%d %d\n",x[i],y[i]);
		}
		
	}
	
	return 0;
}