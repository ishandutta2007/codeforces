#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,id,tot,bes = 123456789,x;
	scanf("%d%d%d",&n,&id,&tot);
	for(int i=1; i<=n; i++){
		scanf("%d",&x);
		if(x != 0 && x <= tot){
			bes = min(bes, (int)labs(i-id) * 10);
		}
	}
	printf("%d\n",bes);
	return 0;
}