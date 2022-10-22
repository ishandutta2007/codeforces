#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<pair<int,int>,int> > p;
priority_queue<pair<pair<int,int>,int> > q;
int n;
int x[600000];
int main() {
	scanf("%d",&n);
	int a,b;
	for(int i=0;i<n;i++) {
		scanf("%d %d",&a,&b);
		if(a<b) p.push({{a,b},i+1});
		else q.push({{b,a},i+1});
	}
	if(p.size() > q.size()) {
		printf("%d\n",p.size());
		while(p.size()>0) {
			printf("%d ",p.top().second);
			p.pop();
		}
	}
	else {
		printf("%d\n",q.size());
		n=0;
		while(q.size()>0) {
			x[n++]=q.top().second;
			//printf("%d ",p.top().second.second);
			q.pop();
		}
		for(int i=n-1;i>=0;i--) printf("%d ",x[i]);
	}
	return 0;
}