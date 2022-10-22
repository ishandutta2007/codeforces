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
		deque<int> D(n);
		rep(i,n){
			scanf("%d",&D[i]);
		}
		vector<int> cnt(n+1,0);
		rep(i,n){
			cnt[D[i]]++;
		}
		set<int> s;
		rep(i,n+1){
			if(cnt[i]==0){
				s.insert(i);
			}
		}
		
		vector<int> ans;
		rep(i,n){
			int mex = *(s.begin());
			vector<bool> t(mex,false);
			ans.push_back(mex);
			int c = 0;
			int ind;
			if(mex==0){
				ind = i;
			}
			else{
				for(int j=i;j<n;j++){
					if(D[j]>=mex)continue;
					if(t[D[j]]==false){
						t[D[j]] = true;
						c++;
					}
					
					if(c == mex){
						ind = j;
						break;
					}
				}
			}
			for(int j=i;j<=ind;j++){
				cnt[D[j]] --;
				if(cnt[D[j]]==0)s.insert(D[j]);
			}
			i = ind;
		}
		cout<<ans.size()<<endl;
		rep(i,ans.size()){
			if(i!=0)printf(" ");
			printf("%d",ans[i]);
		}
		cout<<endl;
	}
	
	return 0;
}