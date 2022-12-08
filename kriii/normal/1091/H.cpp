#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

bool isp[200200],chk[200200]; int pr[200200],cnt[200200];
short mex[200200];
vector<int> in[1000];

int main()
{
	for (int i=2;i*i<200200;i++) if (!isp[i]){
		for (int j=i*i;j<200200;j+=i) isp[j] = 1;
		chk[i*i] = 1;
	}

	for (int i=2;i<200200;i++) pr[i] = i;

	for (int i=2;i<200200;i++) if (!isp[i]){
		chk[i] = 1;
		for (int j=i;j<200200;j+=i){
			pr[j] /= i; cnt[j]++;
		}
	}

	int N,F; scanf ("%d %d",&N,&F);
	for (int i=2;i<200200;i++) if (pr[i] == 1 && cnt[i] == 2){
		chk[i] = 1;
	}
	chk[F] = 0;

	in[0].push_back(0);
	for (int i=1;i<200200;i++){
		while (1){
			bool g = false;
			for (int p : in[mex[i]]){
				if (chk[i-p]){
					g = true;
					break;
				}
			}
			if (!g) break;
			mex[i]++;
		}
		in[mex[i]].push_back(i);
	}

	int g = 0;
	for (int i=0;i<N;i++){
		int a,b,c; scanf ("%d %d %d",&a,&b,&c);
		g ^= mex[b-a-1];
		g ^= mex[c-b-1];
	}

	puts(g?"Alice":"Bob");
	puts(!g?"Alice":"Bob");

	return 0;
}