#include <stdio.h>
#include <algorithm>
using namespace std;

int B,K;

int main()
{
	scanf ("%d %d",&B,&K);

	int r = 0;
	for (int i=K-1;i>=0;i--){
		int x; scanf ("%d",&x);
		if (B % 2){
			if (x % 2) r ^= 1;
		}
		else{
			if (i == 0){
				if (x % 2) r ^= 1;
			}
		}
	}
	puts(r?"odd":"even");

	return 0;
}