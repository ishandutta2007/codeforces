#include <bits/stdc++.h>
using namespace std;

vector<int> w[1<<20];
vector<int> t[1<<20];
int x[1<<20];
bool vis[1<<20];
int n;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",x+i);
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			int j=i;
			while(!vis[j]){
				w[i].push_back(j);
				vis[j]=true;
				j=x[j];
			}
			t[w[i].size()].push_back(i);
		}
	}
	bool r=true;
	for(int l=1;r&&l<=n;++l){
		if(l%2){
			for(int i=0;i<t[l].size();++i){
				int q=t[l][i];
				for(int j=0;j<l;++j){
					x[w[q][j]]=w[q][(j+l/2+1)%l];
				}
			}
		}
		else if(t[l].size()%2)r=false;
		else {
			for(int i=0;i<t[l].size();i+=2){
				int q1=t[l][i],q2=t[l][i+1];
				for(int j=0;j<l;++j){
					x[w[q1][j]]=w[q2][j];
					x[w[q2][j]]=w[q1][(j+1)%l];
				}
			}
		}
	}
	if(r){
		printf("%d",x[1]);
		for(int i=2;i<=n;++i)printf(" %d",x[i]);
		puts("");
	}
	else puts("-1");
	return 0;
}