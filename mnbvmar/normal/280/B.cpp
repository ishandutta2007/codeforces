#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <set>

using namespace std;

int n;
pair<int,int> s[100005];
int ns[100005];
set<int> SP, SM;

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){ scanf("%d", &ns[i]); s[i].second = i; s[i].first = -ns[i]; }

	if(n==1){printf("0\n"); return 0;}

	sort(s,s+n);

	SP.insert(s[0].second);
	SM.insert(-s[0].second);

	int maxv = 0;
	for(int i = 1; i < n; i++){
		int ssec = s[i].second;
		//printf("%d\n", ssec);
		set<int>::iterator it = SP.insert(ssec).first;
		if(++it != SP.end()){
			//printf("%d(%d,%d)", *it, ns[*it],ns[ssec]);
			int val = ns[*it] ^ ns[ssec];
			if(val > maxv) maxv = val;
		}

		it = SM.insert(-ssec).first;
		if(++it != SM.end()){
			//printf("%d[%d,%d]",-*it, ns[-*it],ns[ssec]);
			int val = ns[-*it] ^ ns[ssec];
			if(val > maxv) maxv = val;
		}
	}
	printf("%d\n", maxv);
}