#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		vector <int> R(m),W(m);
		int r=0,w=0;
		for(int i=0;i<m;i++){
			scanf("%d%d",&R[i],&W[i]);
			r=max(r,R[i]);
			w=max(w,W[i]);
		}
		if(r+w>n){
			puts("IMPOSSIBLE");
		} else{
			for(int i=0;i<r;i++) printf("R");
			for(int i=0;i<n-r;i++) printf("W");
			puts("");
		}
	}
}