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
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

const int maxN= 100000 + 5;

int n,a,b;
int res[maxN];

struct node{
	int c,id;

	node (int c=-1, int id=-1) : c(c), id(id) {}

}t[maxN];
/******************************/
inline bool cmp1 (const node &fir, const node &sec){
	return (fir.c!=sec.c) ? fir.c>sec.c : fir.id<sec.id;
}
/******************************/
inline bool cmp2 (const node &fir, const node &sec){
	return (fir.c!=sec.c) ? fir.c<sec.c : fir.id<sec.id;
}
/******************************/
int main(){
	scanf ("%d%d%d", &n, &a, &b);
	for (int i=1;i<=n;i++){
		scanf ("%d", &t[i].c);
		t[i].id= i;
	}

	if (a==b){
		for (int i=1;i<=a;i++)
			printf ("1 ");
		for (int i=1;i<=b;i++)
			printf ("2 ");
		printf("\n");
		return 0;
	}

	if (a<b)
		sort (t+1, t+n+1, cmp1);

	if (a>b)
		sort (t+1, t+n+1, cmp2);

	for (int i=1;i<=a;i++)
		res[t[i].id]= 1;
	for (int i=a+1;i<=n;i++)
		res[t[i].id]= 2;

	for (int i=1;i<=n;i++)
		printf ("%d ", res[i]);
	printf ("\n");

	return 0;
}