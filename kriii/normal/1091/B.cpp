#include <stdio.h>
#include <algorithm>
using namespace std;

int N,ax[1010],ay[1010],bx[1010],by[1010];
pair<int, int> p[1010],q[1010];

int main()
{
	scanf ("%d",&N);
	for (int i=0;i<N;i++) scanf ("%d %d",&ax[i],&ay[i]);
	for (int i=0;i<N;i++) scanf ("%d %d",&bx[i],&by[i]), p[i] = {bx[i],by[i]};
	sort(p,p+N);

	for (int i=0;i<N;i++){
		int cx = ax[0] + bx[i], cy = ay[0] + by[i];
		for (int j=0;j<N;j++) q[j] = {cx-ax[j],cy-ay[j]};
		sort(q,q+N);

		bool g = 1;
		for (int j=0;j<N;j++) if (p[j] != q[j]) g = 0;
		if (g){
			printf ("%d %d\n",cx,cy);
			break;
		}
	}

	return 0;
}