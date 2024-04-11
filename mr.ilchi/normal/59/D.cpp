/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxN= 100000+5;

bool mark[3*maxN];
int n, goal;
int pos[3*maxN];

struct team{
	int a,b,c;

	inline void read(){
		scanf ("%d%d%d", &a, &b, &c);
		if (pos[a] > pos[b])
			swap (a,b);
		if (pos[a] > pos[c])
			swap (a,c);
	}

}a[maxN];	
/****************************/
int main(){
	scanf ("%d", &n);
	for (int i=1, leni= 3*n;i<= leni;i ++){
		int tmp;
		scanf ("%d", &tmp);
		pos[tmp]= i;
	}
	for (int i=1;i<= n;i ++)
		a[i].read();
	
	scanf ("%d", &goal);

	int N=3*n;
	for (int i=1;i<= n;i ++){
		mark[a[i].a]= mark[a[i].b]= mark[a[i].c]= true;
		if (a[i].a==goal){
			int lenj= max(a[i].b, a[i].c);
			for (int j=1;j<= lenj;j ++) 
				if (j!=goal && mark[j])
					printf ("%d ", j);
			
			for (int j=lenj+1;j<= N;j ++)
				mark[j]= false;
			for (int j=1;j<= N;j ++) if (j!= goal && !mark[j])
				printf ("%d ", j);
			
			printf ("\n");
			return 0;
		}
		else if (a[i].b==goal || a[i].c==goal){
			for (int j=1;j<= N;j ++) if (j!=goal)
				printf ("%d ", j);

			printf ("\n");
			return 0;
		}
	}
	return 0;
}