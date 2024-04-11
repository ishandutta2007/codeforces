#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
 
 
int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n,k;
		cin>>n>>k;
		
		vector<int> a(n);
		rep(i,n)scanf("%d",&a[i]);
		
		vector<int> imos(k*2+3,0);
		
		rep(i,n/2){
			int x = a[i],y = a[n-1-i];
			imos[2] += 2;
			imos[k*2+1] -= 2;
			imos[min(x,y)+1] --;
			imos[max(x,y)+k+1] ++;
			imos[x+y] --;
			imos[x+y+1] ++;
		}
		
		rep(i,imos.size()-1)imos[i+1] += imos[i];
		int ans = Inf;
		for(int i=2;i<=2*k;i++)ans = min(ans,imos[i]);
		
		cout<<ans<<endl;
		
	}
	
	return 0;
}