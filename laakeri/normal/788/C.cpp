#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int a[1010];

int d[4040];

int main(){
	int n,k;
	scanf("%d %d", &n, &k);
	int mi=1001;
	int ma=-1;
	for (int i=0;i<k;i++){
		int aa;
		scanf("%d", &aa);
		a[aa]=1;
		mi=min(mi, aa);
		ma=max(ma, aa);
	}
	const int C=2000;
	queue<int> bfs;
	for (int i=0;i<=1000;i++){
		if (a[i]){
			bfs.push(i-n+C);
			d[i-n+C]=1;
		}
	}
	while (!bfs.empty()){
		int x=bfs.front();
		bfs.pop();
		if (x-C==0){
			printf("%d\n", d[x]);
			return 0;
		}
		for (int i=0;i<=1000;i++){
			if (a[i]){
				int ne=x+i-n;
				if (ne>=0&&ne<2*C&&d[ne]==0){
					d[ne]=d[x]+1;
					bfs.push(ne);
				}
			}
		}
	}
	printf("-1\n");
}