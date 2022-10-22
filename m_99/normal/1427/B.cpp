#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 2000000000


int main(){	

	int t;
	cin>>t;
	
	rep(_,t){
		int n,k;
		scanf("%d %d",&n,&k);
		string s;
		cin>>s;
		deque<char> d;
		rep(i,n){
			d.push_back(s[i]);
		}
		
		int ans = 0;
		
		rep(i,n){
			if(s[i]=='W'){
				if(i!=0&&s[i-1]=='W')ans+=2;
				else ans++;
			}
		}
		
		if(ans==0){
			if(k>0){
				ans++;
				k--;
			}
			
			ans += min(k,n-1)*2;
			printf("%d\n",ans);
			continue;
		}
		
		int lose = 0;
		while(d.size()>0&&d.front()=='L'){
			lose++;
			d.pop_front();
		}
		while(d.size()>0&&d.back()=='L'){
			lose++;
			d.pop_back();
		}
		
		

		int now = 0;
		vector<int> x;
		while(d.size()>0){
			d.pop_back();
			int cnt = 0;
			while(d.size()>0&&d.back()=='L'){
				d.pop_back();
				cnt++;
			}
			if(cnt>0)x.push_back(cnt);
		}
		
		sort(x.rbegin(),x.rend());

		while(x.size()!=0){
			if(x.back() <= k){
				k -= x.back();
				ans += x.back()*2;
				ans++;
				x.pop_back();
			}
			else{
				ans += k*2;
				k = 0;
				break;
			}
		}
		
		ans += min(k,lose)*2;
		
		printf("%d\n",ans);
			
		
	}
	
    return 0;
}