#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000

vector<int> X;
int root;
set<int> ans;
vector<int> depth;

void dfs(vector<vector<int>> &E,int now){
	depth[now] = X.size();
	X.push_back(now);
	
	for(int i=0;i<E[now].size();i++){
		int to = E[now][i];
		if(depth[to]==Inf){
			dfs(E,to);
		}
		else{
			int num = depth[now]-depth[to]+1;
			if(num>=root){
				printf("2\n%d\n",num);
				for(int j=depth[to];j<=depth[now];j++){
					if(j!=depth[to])printf(" ");
					printf("%d",X[j]+1);
				}
				printf("\n");
				exit(0);
			}
		}
	}
	
	if(ans.count(now)){
		for(int i=0;i<E[now].size();i++){
			int to = E[now][i];
			ans.erase(to);
		}
	}
	
	X.pop_back();
	
}

int main(){
	
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<n;i++)ans.insert(i);
	
	root = 1;
	while(root*root<n)root++;
	
	vector<vector<int>> E(n,vector<int>());
	
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		a--;b--;
		
		E[a].push_back(b);
		E[b].push_back(a);
	}
	
	depth.resize(n,Inf);
	
	dfs(E,0);
	
	printf("1\n");
	int k = 0;
	for(auto a:ans){
		if(k!=0)printf(" ");
		printf("%d",a+1);
		k++;
		if(k==root)break;
	}
	printf("\n");
	
	return 0;
}