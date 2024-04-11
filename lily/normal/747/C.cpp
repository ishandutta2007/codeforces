/*	Never stop fighting for what you believe in.	*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

struct pp {
	int x,v;
	pp(){}
	pp(int a,int b):x(a),v(b){}
	bool operator < (pp a) const {
		return v>a.v;
	}
};

int n,Q;
priority_queue < int,vector<int>,greater<int> > q;
priority_queue <pp> p;

int main() {
	scanf("%d%d",&n,&Q);
	for (int i=1;i<=n;i++) q.push(i);
	for (int i=1,t,k,d;i<=Q;i++) {
		scanf("%d%d%d",&t,&k,&d);
		while (!p.empty() && p.top().v<=t) q.push(p.top().x),p.pop();
		if (k>q.size()) puts("-1");
		else {
			int tot=0;
			while (k--) {
				tot+=q.top();p.push(pp(q.top(),t+d));q.pop();
			}
			printf("%d\n",tot);
		}
	}

	return 0;
}