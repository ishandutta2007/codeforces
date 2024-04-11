#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int k,n,m;
		scanf("%d %d %d",&k,&n,&m);
		vector<int> a(n),b(m);
		rep(i,n)scanf("%d",&a[i]);
		rep(i,m)scanf("%d",&b[i]);
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		vector<int> ans;
		while(a.size()!=0||b.size()!=0){
			if(a.size()!=0){
				if(a.back()==0){
					k++;
					ans.push_back(a.back());
					a.pop_back();
					continue;
				}
				if(a.back()<=k){
					ans.push_back(a.back());
					a.pop_back();
					continue;
				}
			}
			if(b.size()!=0){
				if(b.back()==0){
					k++;
					ans.push_back(b.back());
					b.pop_back();
					continue;
				}
				if(b.back()<=k){
					ans.push_back(b.back());
					b.pop_back();
					continue;
				}
			}
			break;
		}
		
		if(ans.size()==n+m){
			rep(i,n+m){
				if(i!=0)printf(" ");
				printf("%d",ans[i]);
			}
			printf("\n");
		}
		else{
			printf("-1\n");
		}
		
	}
	
	return 0;
}