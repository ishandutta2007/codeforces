#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int n;
vector<int> e[505];
int deg[505],d[505],q[505],op,cl;
bool inq[505];
int main(){
	int m;
	scanf("%d%d",&n,&m);
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		d[y]++;
	}
	for(int Q = 1; Q <= n; Q++){
		memcpy(deg,d,sizeof(deg));
		memset(inq,0,sizeof(inq));
		op = cl = 0;
		for(int i=1; i<=n; i++)if(deg[i] == 0){
			q[op++] = i;
			inq[i] = true;
		}
		bool bad = false;
		while(cl < n){
			if(op == cl){
				if(deg[Q] == 1 && !inq[Q]){
					q[op++] = Q;
					inq[Q] = true;
				}else{
					bad = true;
					break;
				}
			}
			int x = q[cl++];
			for(vector<int>::iterator it = e[x].begin(); it != e[x].end(); it++){
				int y = *it;
				--deg[y];
				if(deg[y] == 0 && !inq[y]){
					inq[y] = true;
					q[op++] = y;
				}
			}
		}
		if(!bad){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}