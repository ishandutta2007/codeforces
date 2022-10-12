#include<bits/stdc++.h>
using namespace std;
int n;
struct pnt{
	int c[3],id;
} a[55555];
bool cmp(const pnt&a,const pnt&b){
	if(a.c[0] != b.c[0])return a.c[0] < b.c[0];
	if(a.c[1] != b.c[1])return a.c[1] < b.c[1];
	return a.c[2] < b.c[2];
}
int recur(int s,int e,int x){
	if(s + 1 == e)return a[s].id;
	vector<int> lef;
	for(int i=s,j; i<e; i=j){
		for(j=i; j<e && a[j].c[x] == a[i].c[x]; j++);
		int w = recur(i,j,x+1);
		if(w != -1)lef.push_back(w);
	}
	int ret = -1;
	if(lef.size() % 2 != 0){
		ret = lef.back();
		lef.pop_back();
	}
	for(int i=0; i<lef.size(); i+=2)
		printf("%d %d\n",lef[i]+1, lef[i+1]+1);
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d%d%d",&a[i].c[0],&a[i].c[1],&a[i].c[2]);
		a[i].id = i;
	}
	sort(a,a+n,cmp);
	recur(0,n,0);
	return 0;
}