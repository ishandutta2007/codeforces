#include <stdio.h>
#include <map>
using namespace std;

map<int, int> mem2[30003];
int mem[30003][500];
int gem[30003];

int col(int x, int d)
{
	if (d == 0) return 0;
	if (x > 30000) return 0;
	if (d < 500 && mem[x][d] != -1) return mem[x][d];
	if (d >= 500 && mem2[x].count(d)) return mem2[x][d];
	int &r = d < 500 ? mem[x][d] : mem2[x][d];

	int a = col(x+d,d);
	int b = col(x+d-1,d-1);
	int c = col(x+d+1,d+1);
	r = a;
	if (r < b) r = b;
	if (r < c) r = c;
	r += gem[x];
	return r;
}

int main()
{
	int N,D;

	for (int i=0;i<=30000;i++) for (int j=0;j<500;j++) mem[i][j] = -1;
	scanf ("%d %d",&N,&D); while (N--){
		int x; scanf ("%d",&x);
		gem[x]++;
	}

	printf ("%d\n",col(D,D));

	return 0;
}