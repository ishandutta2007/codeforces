#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
	int n;
	scanf("%d", &n);
	printf("YES\n");
	int inf=1e9+4;
	for (int i=0;i<n;i++){
		int x1,y1,x2,y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		x1+=inf;
		y1+=inf;
		int c=0;
		if (x1%2==0&&y1%2==0) c=1;
		else if(x1%2==0&&y1%2==1) c=2;
		else if(x1%2==1&&y1%2==0) c=3;
		else if(x1%2==1&&y1%2==1) c=4;
		
		printf("%d\n", c);
	}
}