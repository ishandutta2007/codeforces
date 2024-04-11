#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){	
	
	int n;
	cin>>n;
	
	vector<int> a(n);
	rep(i,n){
		scanf("%d",&a[i]);
	}
	
	
	vector<pair<int,int>> ans;
	deque<pair<int,int>> D1;
	deque<pair<int,int>> Dall;
	int y = n;
	for(int i=n-1;i>=0;i--){
		if(a[i]==0)continue;
		if(a[i]==1){
			ans.emplace_back(i+1,y);
			D1.emplace_front(y,i);
			y--;
			continue;
		}
		if(a[i]==2){
			if(D1.size()==0){
				cout<<-1<<endl;
				return 0;
			}
			ans.emplace_back(i+1,D1.back().first);
			Dall.emplace_front(D1.back().first,i+1);
			D1.pop_back();
			continue;
		}
		if(a[i]==3){
			int xx = -1;
			if(Dall.size()>0){
				xx = Dall.back().second;
				Dall.pop_back();
			}
			else if(D1.size()>0){
				xx = D1.back().second+1;
				D1.pop_back();
			}
			if(xx==-1){
				cout<<-1<<endl;
				return 0;
			}
			
			ans.emplace_back(i+1,y);
			ans.emplace_back(xx,y);
			Dall.emplace_front(y,i+1);
			y--;
		}
	}
		
	
	cout<<ans.size()<<endl;
	
	rep(i,ans.size()){
		printf("%d %d\n",ans[i].second,ans[i].first);
	}
	
	
    return 0;
}