#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	
	int n;
	cin>>n;
	vector<pair<int,int>> a;
	
	rep(i,n){
		int t;
		scanf("%d",&t);
		t--;
		
		if(a.size()==0||a.back().first!=t){
			a.emplace_back(t,1);
		}
		else a.back().second++;
	}
	
	n = a.size();
	
	int x = -1,y = -1;
	vector<int> last(100005,-100);
	int sum = 0;
	int ans = 0;
	rep(i,n){
		int aa = a[i].first;
		int t = min(2,a[i].second);
		
		if(x!=aa&&y!=aa){
			if(t==2)x = aa;
			y = aa;
			ans += t;
		}
		else{
			if(x!=aa&&y==aa)swap(x,y);
			if(t==1){
				y = aa;
				ans++;
			}
			else{
				if(sum-last[aa]>=2){
					ans += 2;
					x = aa;
					y = aa;
				}
				else{
					ans++;
					y = aa;
				}
			}
		}
		
		if(t==2)last[aa] = sum+t;
		else if(sum-last[aa]==1)last[aa] = sum+t;
		sum += t;
	}
	
	cout<<ans<<endl;
	
	return 0;
}