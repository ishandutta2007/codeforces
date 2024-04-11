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
		
		vector<int> a(n);
		rep(i,n){
			scanf("%d",&a[i]);
		}
		vector<int> l,r,cnt;
		rep(i,n){
			int mini = Inf,ind = -1;
			for(int j=i;j<n;j++){
				if(mini > a[j]){
					mini = a[j];
					ind = j;
				}
			}
			if(ind==i)continue;
			l.push_back(i);
			r.push_back(ind);
			cnt.push_back(r.back()-l.back());
			
			rep(j,cnt.back()){
				int t = a[i];
				rep(k,cnt.back()){
					a[i+k] = a[i+k+1];
				}
				a[r.back()] = t;
				//break;
			}
			/*
			rep(j,a.size()){
				cout<<a[j]<<',';
			}
			cout<<endl;
			*/
		}
		
		cout<<l.size()<<endl;
		rep(i,l.size()){
			printf("%d %d %d\n",l[i]+1,r[i]+1,cnt[i]);
		}
		
	}
	
	return 0;
}