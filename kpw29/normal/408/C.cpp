#include <bits/stdc++.h>
#define e1 first
#define e2 second
#define mp make_pair
using namespace std;
int a, b, n;
typedef pair <int, int> BONG;
typedef double ld;

int odl(BONG a, BONG b)
{
	return ((a.e1 - b.e1) * (a.e1 - b.e1)) + ((a.e2 - b.e2) * (a.e2 - b.e2));
}
int main()
{
	scanf("%d%d", &a, &b);
	pair <int, int> p = mp(0,0);
	int kwa = a*a, kwb = b*b;
	int bok = kwa + kwb;
	for (int i=1; i*i < kwa; ++i)
	  {
		  int drugi = sqrt(kwa - i * i);
		  if (drugi * drugi + i * i == kwa)
		  {
			  for (int j=-b + 1; j < b; ++j)
			 {
			  int drug = sqrt(kwb - j * j);
			  if (drug * drug + j * j == kwb)
			  {
				  if (bok == odl(mp(i, drugi), mp(j, drug)) && drug != drugi && i != j && j != 0 && drug != 0 && drugi != 0)
				  {
					  puts("YES");
					  puts("0 0");
					  printf("%d %d\n", i, drugi);
					  printf("%d %d\n", j, drug);
					  return 0;
				  }
			  }
			}
		  }
	  }
	 puts("NO");
}