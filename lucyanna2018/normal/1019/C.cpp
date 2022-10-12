#include<bits/stdc++.h>
using namespace std;
#define ran 1000010
int n;
vector<int> e[ran];
set<int> all;
int a[ran],la,b[ran],lb;
int main(){
	int m;
	scanf("%d%d",&n,&m);
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
	}
	for(int i=1; i<=n; i++)all.insert(i);
	while(!all.empty()){
		int x = *all.begin();
		a[la++] = x;
		all.erase(x);
		for(auto y : e[x]){
			all.erase(y);
		}
	}
	for(int i=1; i<=n; i++)all.insert(i);
	while(la--){
		int x = a[la];
		if(all.count(x)){
			b[lb++] = x;
			all.erase(x);
			for(auto y : e[x]){
				all.erase(y);
			}
		}
	}
	printf("%d\n",lb);
	for(int i=0; i<lb; i++)
		printf("%d%c",b[i],i<lb-1?' ':'\n');
	return 0;
}