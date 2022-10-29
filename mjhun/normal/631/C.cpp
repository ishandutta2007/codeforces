#include <bits/stdc++.h>
#define mp make_pair
#define fst first
#define snd second
using namespace std;

typedef long long ll;

int n,m;
int a[200005];
int sa[200005];
int t[200005];
int e[200005];
int d[200005];
multiset<int> w;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%d",a+i);
		w.insert(a[i]);
	}
	for(int i=0;i<m;++i){
		scanf("%d%d",t+i,e+i);
	}
	int l=0;
	for(int i=m-1;i>=0;--i){
		while(l<e[i]){
			d[l++]=t[i];
		}
	}
	for(int i=n-1;i>=0;--i){
		multiset<int>::iterator it;
		if(!d[i]){
			it=w.find(a[i]);
		}
		else if(d[i]==1){
			//greater
			it=w.end();it--;
		}
		else {
			it=w.begin();
		}
		sa[i]=*it;
		w.erase(it);
	}
	assert(w.empty());
	printf("%d",sa[0]);
	for(int i=1;i<n;++i)printf(" %d",sa[i]);
	puts("");
	return 0;
}