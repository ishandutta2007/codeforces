#include <cstdio>
using namespace std;
int n;
int main() {
	scanf("%d",&n);
	if (n<=10 || n>21) printf("%d",0); else {
		n-=10;
		if (n==10) printf("15"); else printf("4");
	}
}