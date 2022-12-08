#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

int L; char S[200200]; int C[200200];
int sum[20][200200];

int main()
{
	scanf ("%d %s",&L,S);
	for (int j=0,c=0;j<L;j++){
		int l = S[j] - '0';
		C[j] = c ^ l;
		c = l;
	}
	for (int i=0;i<20;i++){
		for (int j=0;j<L;j++){
			sum[i][j] = C[j];
			if (j - (1 << i) >= 0) sum[i][j] += sum[i][j-(1<<i)];
		}
	}

	int Q; scanf ("%d",&Q); while (Q--){
		int l,r; scanf ("%d %d",&l,&r);
		int c = 1;
		for (int i=1;i<20;i++){
			int u = (r - l + 1) / (1 << i);
			if (u <= 1) break;
			int s = l + (1 << (i-1));
			int e = s + (1 << i) * (u - 1);
			int d = sum[i][e];
			if (s - (1 << i) >= 0) d -= sum[i][s-(1<<i)];
			c += min(d,u-d);
		}
		printf ("%d\n",c/2);
	}

	return 0;
}