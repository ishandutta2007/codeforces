#include <stdio.h>
#include <algorithm>
using namespace std;

int f(int a)
{
	int r = 1; a--;
	while (a >= 7){
		a /= 7;
		r++;
	}
	return r;
}

int main()
{
	int a,b;
	scanf ("%d %d",&a,&b);

	int la = f(a);
	int lb = f(b);
	int ls = la + lb;
	if (ls > 7){
		printf ("%d\n",0);
		return 0;
	}
	int p[7] = {0,1,2,3,4,5,6};
	int l[7] = {0,}, ans = 0;
	do{
		bool good = 0;
		for (int i=0;i<ls;i++) if (p[i] != l[i]){
			good = 1;
			break;
		}
		if (good){
			int x = 0, y = 0;
			for (int i=0;i<la;i++){
				x = x * 7 + p[i];
			}
			for (int i=la;i<ls;i++){
				y = y * 7 + p[i];
			}
			if (x < a && y < b) ans++;
			for (int i=0;i<ls;i++){
				l[i] = p[i];
			}
		}
	}while (next_permutation(p,p+7));
	printf ("%d\n",ans);

	return 0;
}