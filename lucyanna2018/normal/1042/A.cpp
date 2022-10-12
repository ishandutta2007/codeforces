#include<bits/stdc++.h>
using namespace std;
multiset<int> a;
int main(){
	int n,m,x;
	scanf("%d%d",&n,&m);
	int r2 = 0;
	while(n--){
		scanf("%d",&x);
		a.insert(x);
		r2 = max(r2, x + m);
	}
	while(m--){
		int x = *a.begin();
		a.erase(a.begin());
		a.insert(x+1);
	}
	auto tmp = a.end();
	--tmp;
	printf("%d %d\n",*tmp,r2);
	return 0;
}