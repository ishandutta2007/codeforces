#include <stdio.h>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;

const int X = 7000;
vector<int> d[X+1];
bitset<X+1> b[100100],f[X+1],e;
int mu[X+1];

int main()
{
#ifdef __LOCAL
	freopen ("input.txt","r",stdin);
#endif

	mu[1] = 1;
	for (int i=1;i<=X;i++){
		for (int j=i*2;j<=X;j+=i) mu[j] -= mu[i];
	}
	for (int i=1;i<=X;i++) for (int j=i;j<=X;j+=i){
		d[j].push_back(i);
		if (mu[j/i]) f[i][j] = 1;
	}

	int N,Q;
	scanf ("%d %d",&N,&Q); while (Q--){
		int o; scanf ("%d",&o);
		if (o == 1){
			int x,v; scanf ("%d %d",&x,&v);
			b[x] = e;
			for (int w : d[v]) b[x][w] = 1;
		}
		else if (o == 2){
			int x,y,z; scanf ("%d %d %d",&x,&y,&z);
			b[x] = b[y] ^ b[z];
		}
		else if (o == 3){
			int x,y,z; scanf ("%d %d %d",&x,&y,&z);
			b[x] = b[y] & b[z];
		}
		else{
			int x,v; scanf ("%d %d",&x,&v);
			printf ("%d",(b[x]&f[v]).count()%2);
		}
	}

	return 0;
}