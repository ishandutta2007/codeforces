#include <stdio.h>
#include <vector>
using namespace std;
#define min(a,b) ((a<b)?(a):(b))

__int64 MIN; int G[3];
char SI[2];

void go(vector<__int64> V)
{
	int i,j;

	if (V.size() == 1) MIN = min(MIN,V[0]);
	else{
		int i,j,k;
		vector<__int64> Q;
		for (i=0;i<V.size();i++){
			for (j=i+1;j<V.size();j++){
				Q.clear();
				for (k=0;k<V.size();k++) if (k != i && k != j) Q.push_back(V[k]);
				if (G[4-V.size()]) Q.push_back(V[i]*V[j]);
				else Q.push_back(V[i]+V[j]);
				go(Q);
			}
		}
	}
}

int main()
{
	int i; __int64 t;
	vector<__int64> V;
	for (i=0;i<4;i++){
		scanf ("%I64d",&t); V.push_back(t);
	}
	for (i=0;i<3;i++){
		scanf ("%s",SI); G[i] = (SI[0] == '*');
	}

	MIN = 1000000000000000000i64;
	go(V);

	printf ("%I64d\n",MIN);

	return 0;
}