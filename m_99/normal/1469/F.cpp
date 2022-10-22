#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000
#define P pair<int,int>

constexpr int Maxi = 200005;



int main(){
	
	int n,k;
	cin>>n>>k;
	
	vector<int> l(n);
	rep(i,n)scanf("%d",&l[i]);
	
	sort(l.rbegin(),l.rend());
	
	
	
	int ok = Maxi,ng = 0;
	
	while(ok-ng>1){
		int mid = (ok+ng)/2;
		
		vector<int> v(mid+1,0);
		vector<int> imos(mid+1,0);
		
		v[0] = 1;
		
		int cur = 0;
		bool f = false;
		long long sum = 1LL;
		rep(i,n){
			while(v[cur]==0){
				cur++;
				if(cur==mid+1)break;
				imos[cur] += imos[cur-1];
				v[cur] = imos[cur];
			}
			
			if(cur==mid+1)break;
			v[cur]--;
			sum--;
			
			int x = cur;
			
			x += 2;
			if(x>mid)break;
			
			imos[x]++;
			imos[x]++;
			int R = min(mid+1,x+(l[i]-1)/2);
			if(R<=mid)imos[R]--;
			sum += R - x;
			R = min(mid+1,x+(l[i])/2);
			if(R<=mid)imos[R]--;
			sum += R - x;
						
			if(sum>=k){
				f=true;
				break;
			}
		}
		if(f)ok = mid;
		else ng = mid;
	}
	
	if(ok==Maxi)cout<<-1<<endl;
	else cout<<ok<<endl;
	
    return 0;
}