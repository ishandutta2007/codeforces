# include <iostream>
# include <cstdio>
# include <set>
# include <vector>
# include <algorithm>
using namespace std;

set< pair<int,int> >edge;
int c[100010];
int main() {
	int n, m, x, y;
	scanf("%d%d", &n,&m);
	for(int i=0; i<m; i++) {
		scanf("%d%d", &x, &y);
		edge.insert(make_pair(x,y));
		edge.insert(make_pair(y,x));
	}
	
	for(int i=0; i<n; i++) c[i] = i+1;
	
	for(int k=0; k<6000; k++) {
		random_shuffle(c,c+n); c[n] = c[0];

		bool flag = true;
		for(int i=0; i<m; i++) 
			if(edge.find(make_pair(c[i],c[i+1]))!=edge.end()) {flag = false; break;}
		
		if(flag) {
			for(int i=0; i<m; i++)
				printf("%d %d\n",c[i],c[i+1]);
			return 0;
		}
	}
	
	cout << -1 << endl;
	return 0;
}