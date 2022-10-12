#include<bits/stdc++.h>
using namespace std;
int n;pair<int,int> P;
bool f[555555];
queue<pair<int,int> > q;
priority_queue<pair<int,int> > pq;
int main(){
	int w,x,t;
	n = 0;
	for(scanf("%d",&w); w--;){
		scanf("%d",&t);
		if(t == 1){
			scanf("%d",&x);
			++ n;
			P = make_pair(x, -n);
			q.push(P);
			pq.push(P);
		}else
		if(t == 2){
			while(1){
				P = q.front();
				q.pop();
				x = -P.second;
				if(f[x])continue;
				printf("%d ",x);
				f[x] = true;
				break;
			}
		}else{
			while(1){
				P = pq.top();
				pq.pop();
				x = -P.second;
				if(f[x])continue;
				printf("%d ",x);
				f[x] = true;
				break;
			}
		}
	}
	return 0;
}