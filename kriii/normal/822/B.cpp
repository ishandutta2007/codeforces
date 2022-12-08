#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
	int N,M;
	scanf ("%d %d",&N,&M);
	char S[1010],T[1010];
	scanf ("%s %s",S,T);

	vector<int> U;
	for(int i=1;i<=N;i++) U.push_back(i);
	for (int i=0;i<=M-N;i++){
		vector<int> dif;
		for (int j=0;j<N;j++) if (T[i+j] != S[j]) dif.push_back(j+1);
		if (U.size() > dif.size()) U = dif;
	}

	printf ("%d\n",U.size());
	for (int i=0;i<U.size();i++) printf ("%d%c",U[i],i+1<U.size()?' ':'\n');

	return 0;
}