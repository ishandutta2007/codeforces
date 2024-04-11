#include<bits/stdc++.h>
using namespace std;
#define ran 333333
int n;
vector<pair<int,int> > e[ran];
int q[ran],op,cl;
bool f[ran],g[ran];
int main(){
	int y,x;
	scanf("%d%d%d",&n,&y,&x);
	while(y--){
		scanf("%d",&x);
		f[x] = true;
	}
	for(int i=1; i<n; i++){
		scanf("%d%d",&x,&y);
		e[x].push_back(make_pair(y,i));
		e[y].push_back(make_pair(x,i));
	}
	op=cl=0;
	for(int i=1; i<=n; i++)
		if(f[i])
			q[op++] = i;
	while(cl<op){
		int x = q[cl++];
		for(vector<pair<int,int> >::iterator it = e[x].begin(); it!=e[x].end(); it++){
			int y = it->first;
			if(!f[y]){
				f[y] = true;
				q[op++] = y;
				g[it->second] = true;
			}
		}
	}
	int tot=0;
	for(int i=1; i<n; i++)
		if(!g[i])tot++;
	printf("%d\n",tot);
	for(int i=1; i<n; i++)
		if(!g[i]){
			--tot;
			printf("%d%c",i,tot?' ':'\n');
		}
	return 0;
}