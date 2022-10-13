#include<bits/stdc++.h>
#define ran 111111
using namespace std;
int n,pos;
vector<pair<int,int> > e[ran];
int d[ran];//minimum distance between 0 & i
int d2[ran];//minimum distance between n-1 & i
int q[ran],op,cl;

int ace[ran];
int ancestor(int x){
	return x-ace[x]?ace[x]=ancestor(ace[x]):x;
}
void bfs(int*d,int st){
	memset(d,-1,sizeof(int)*n);
	op = cl = 0;
	q[op++] = st;
	d[st] = 0;
	while(cl!=op){
		int x = q[cl++];
		for(vector<pair<int,int> >::iterator it = e[x].begin(); it!=e[x].end(); it++){
			int y = it->first;
			if(d[y] == -1){
				d[y] = d[x] + 1;
				q[op++] = y;
			}
		}
	}
}

int fat[ran],di[ran];
struct node{
	int id,dig;
	node(){}
	node(int _id,int _dig){
		id = _id;
		dig = _dig;
	}
};
bool operator < (const node&y,const node&x){
	if(d[x.id] != d[y.id])
		return d[x.id] < d[y.id];
	if(x.dig != y.dig)
		return x.dig < y.dig;
	return false;
}

priority_queue<node> qq;
void dij(){
	memset(di,-1,sizeof(int)*n);
	qq.push(node(0,0));
	di[0] = 0;
	while(!qq.empty()){
		int vert = qq.top().id, dig = qq.top().dig;
		qq.pop();
		if(dig != di[vert])continue;

		if(ancestor(vert) == ancestor(n-1)){
			pos = vert;
			break;
		}

		for(vector<pair<int,int> >::iterator it = e[vert].begin(); it!=e[vert].end(); it++){
			int y = it->first;
			if(d[y] == d[vert]+1){
				if(di[y] == -1 || di[y] > it->second){
					fat[y] = vert;
					di[y] = it->second;
					qq.push(node(y,di[y]));
				}
			}
		}
	}
}

char out[ran];int lo;
int d3[ran],fat3[ran],oo[ran];int loo;
void bfs3(){
	memset(d3,-1,sizeof(int)*n);
	op = cl = 0;
	q[op++] = 0;
	d3[0] = 0;
	while(cl!=op){
		int x = q[cl++];
		for(vector<pair<int,int> >::iterator it = e[x].begin(); it!=e[x].end(); it++){
			int y = it->first;
			if(d3[y] == -1 && it->second == (d3[x]<lo?out[d3[x]]:'0') - '0'){
				d3[y] = d3[x] + 1;
				fat3[y] = x;
				q[op++] = y;
			}
		}
	}
}

int main(){
	int m;
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++)
		ace[i] = i;
	while(m--){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		e[x].push_back(make_pair(y,z));
		e[y].push_back(make_pair(x,z));
		if(z == 0)
			ace[ancestor(x)] = ancestor(y);
	}
	bfs(d,0);
	bfs(d2,n-1);
	dij();	
	while(pos != 0){
		out[lo++] = '0'+di[pos];
		pos = fat[pos];
	}
	out[lo] = 0;
	puts(lo==0?"0":out);
	reverse(out,out+lo);
	bfs3();
	for(pos = n-1; pos != 0; pos = fat3[pos])
		oo[loo++] = pos;
	reverse(oo,oo+loo);
	printf("%d\n0",loo+1);
	for(int i=0; i<loo; i++)
		printf(" %d",oo[i]);
	puts("");
	return 0;
}