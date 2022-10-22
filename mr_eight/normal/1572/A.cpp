#include<bits/stdc++.h>
#include<set>
#include<vector>
#include<algorithm>
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
using namespace std;
set<int>s;
vector<int>g[200002];
int n,temp,deg[200002],t2;
int ans,cnt;
int main(){
	int T;
	cin>>T;
	while(T--){
	cin>>n;
	F(i,1,n){
		g[i].clear();
		deg[i]=0;
	}
	ans=cnt=0;
	F(i,1,n){
		scanf("%d",&t2);
		F(j,1,t2){
			scanf("%d",&temp);
			g[temp].push_back(i);
			++deg[i];
		}
		if(!deg[i]){
			s.insert(i);
		}
	}
	int lst=0;
	while(!s.empty()){
		++cnt;
		if(s.lower_bound(lst)!=s.end()){
			lst=*s.lower_bound(lst);
			s.erase(s.lower_bound(lst));
		}else{
			lst=*s.begin();
			s.erase(s.begin());
			++ans;
		}
		for(int j:g[lst]){
			--deg[j];
			if(!deg[j]){
				s.insert(j);
			}
		}
	}
	if(cnt==n){
		cout<<ans+1<<'\n';
	}else puts("-1");	
	}
	
	return 0;
}