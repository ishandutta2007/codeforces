#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int N,K; char S[200200];
int p[200200]; vector<int> q;

int main()
{
	scanf ("%d %d",&N,&K); K =  N - K;
	scanf ("%s",S);
	for (int i=0;i<N;i++) p[i] = -1;
	for (int i=0;i<N;i++){
		if (S[i] == '(') q.push_back(i);
		else{
			p[i] = q.back();
			q.pop_back();
		}
	}
	for (int i=0;i<N;i++) if (p[i] != -1){
		if (K > 0){
			S[i] = S[p[i]] = ' ';
			K -= 2;
		}
	}
	for (int i=0;i<N;i++) if (S[i] != ' ') putchar(S[i]);

	return 0;
}