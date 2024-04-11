#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<int> d(n,0);
		for(int i=1;i<n;i++){
			int p;
			scanf("%d",&p);
			p--;
			d[p]++;
		}
		d.push_back(1);
		sort(d.rbegin(),d.rend());
		int ok = n,ng = -1;
		while(ok-ng>1){
			auto dd = d;
			int mid = (ok+ng)/2;
			
			int need = 0;
			rep(i,mid){
				if(i >= dd.size() || dd[i]==0){
					need--;
				}
				else{
					need += max(0,dd[i] - (mid-i));
				}
			}
			if(dd.size()>mid && dd[mid]>0)ng = mid;
			else{
				if(need<=0)ok = mid;
				else ng = mid;
			}
		}
		cout<<ok<<endl;
		
		
	}
		
	return 0;
}