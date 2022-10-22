#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 1000000000000

int get(vector<int> &C){
	
	for(int i=1;i<=C.size();i++){
		if(C.size()%i!=0)continue;
		int x = C.size()/i;
		for(int j=0;j<i;j++){
			bool f = true;
			for(int k=j;k<C.size();k+=i){
				if(C[k]!=C[j]){
					f=false;
					break;
				}
			}
			if(f)return i;
		}
	}
	return 1;
}

int main() {
	
	int T;
	cin>>T;
	
	for(int _=0;_<T;_++){
		int n;
		scanf("%d",&n);
		
		vector<int> p(n);
		for(int i=0;i<n;i++){
			scanf("%d",&p[i]);
			p[i]--;
		}
		
		vector<int> c(n);
		for(int i=0;i<n;i++){
			scanf("%d",&c[i]);
		}
		int ans  = 10000000;
		vector<bool> visited(n,false);
		for(int i=0;i<n;i++){
			if(visited[i])continue;
			vector<int> C;
			int now = i;
			while(true){
				if(visited[now])break;
				visited[now] = true;
				C.push_back(c[now]);
				now = p[now];
			}
			ans = min(ans,get(C));
		}
		printf("%d\n",ans);//cout<<ans<<endl;
	}
				
    return 0;
}