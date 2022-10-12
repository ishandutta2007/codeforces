#include<bits/stdc++.h>
#include<bitset>
using namespace std;
#define ran 2022
int n;
vector<int> e[ran];
int res[ran];
bitset<2001> a[ran];
int main(){
	int _,m;
	for(scanf("%d",&_); _--;){
		scanf("%d%d",&n,&m);
		for(int i=0; i<n; i++)e[i].clear();
		while(m--){
			int x,y;
			scanf("%d%d",&x,&y);
			--x;--y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		bool flag = true;
		for(int i=0; i<n; i++)
			if(e[i].size() % 2)
				flag = false;
		if(flag){
			printf("1\n");
			for(int i=0; i<n; i++)
				printf("1%c",i<n-1?' ':'\n');
			continue;
		}
		for(int i=0; i<n; i++){
			int z = 0;
			a[i].reset();
			for(auto x : e[i]){
				z ^= 1;
				a[i].set(x);
			}
			if(z){
				a[i].set(i);
				a[i].set(n);
			}
		}
		for(int i=0; i<n; i++){
			int p = -1;
			for(int j=i; j<n; j++)if(a[j].test(i)){
				p=j;
				break;
			}
			if(p==-1)continue;
			swap(a[p],a[i]);
			for(int j=i+1; j<n; j++)if(a[j].test(i))
				a[j] ^= a[i];
		}
		for(int i=n-1; i>=0; i--){
			if(a[i].test(n))res[i] = 1;else
				res[i] = 0;
			for(int j=i+1; j<n; j++)if(a[i].test(j))
				res[i]^=res[j];
		}
		printf("2\n");
		for(int i=0; i<n; i++)
			printf("%d%c",2-res[i], i<n-1?' ':'\n');
	}
	return 0;
}