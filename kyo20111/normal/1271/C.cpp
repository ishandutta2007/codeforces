#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,chk[4],sx,sy;

int main(){
	scanf("%d %d %d",&n,&sx,&sy);
	for(int i=1;i<=n;i++){
		int x, y; scanf("%d %d",&x,&y);
		if(sx == x && sy > y) chk[0]++;
		else if(sx == x && sy < y) chk[1]++;
		else if(sx > x && sy == y) chk[2]++;
		else if(sx < x && sy == y) chk[3]++;
		else if(sx > x && sy > y) chk[0]++, chk[2]++;
		else if(sx > x && sy < y) chk[1]++, chk[2]++;
		else if(sx < x && sy > y) chk[0]++, chk[3]++;
		else if(sx < x && sy < y) chk[1]++, chk[3]++;
	}

	if(chk[0] >= chk[1] && chk[0] >= chk[2] && chk[0] >= chk[3]) printf("%d\n%d %d",chk[0],sx,sy-1);
	else if(chk[1] >= chk[0] && chk[1] >= chk[2] && chk[1] >= chk[3]) printf("%d\n%d %d",chk[1],sx,sy+1);
	else if(chk[2] >= chk[1] && chk[2] >= chk[0] && chk[2] >= chk[3]) printf("%d\n%d %d",chk[2],sx-1,sy);
	else printf("%d\n%d %d",chk[3],sx+1,sy);
}