#include <stdio.h>
#include <algorithm>

bool qwe(int i1,int i2){
	if(i1>i2) return true;
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	#endif
	int i,n,a1[100],a2[100];
	bool r,t;
	char c;
	r=true;
	scanf("%d\n",&n);
	for(i=0;i<n;i++){
		scanf("%c",&c);
		a1[i]=c-'0';
	}
	for(i=0;i<n;i++){
		scanf("%c",&c);
		a2[i]=c-'0';
	}
	std::sort(a1,a1+n);
	std::sort(a2,a2+n);
	if(a1[0]>a2[0]) t=true;
	else{
		t=false;
		if(a1[0]==a2[0]) r=false;
	}
	for(i=1;i<n;i++){
		if(t){
			if(a1[i]<=a2[i]) r=false;
		}
		else if(a1[i]>=a2[i]) r=false;
	}
	if(r) printf("YES");
	else printf("NO");
}