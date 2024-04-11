

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define y1 kqwjeklqwjekq

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<pair<int,int>,int> ii;

int x1,y1,x2,y2;

int main() {
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	if(x1==x2) {
		printf("%d\n",4+2*abs(y1-y2)+2);
	} else if (y1==y2) {
		printf("%d\n",4+2*abs(x1-x2)+2);
	} else if(y1<y2) {
		printf("%d\n",2*((y2-y1)+1)+2*(abs(x1-x2)+1));
	} else if(y1>y2) {
		printf("%d\n",2*((y1-y2)+1)+2*(abs(x1-x2)+1));
	}
	return 0;
}