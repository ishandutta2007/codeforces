#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
using namespace std;
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
typedef long long ll;

int n,s;
int a[200005];
multiset<int> w;
int m,r;

int main(){
	scanf("%d%d",&n,&s);s--;
	fore(i,0,n)scanf("%d",a+i);
	if(a[s])r++;
	fore(i,0,n)if(i!=s)w.insert(a[i]);
	m=1;
	while(w.count(m))m++;
	while(!w.empty()){
		multiset<int>::iterator it=w.end();it--;
		if(*it<m)break;
		r++;
		if(w.count(0))w.erase(w.find(0));
		else w.erase(it);
		m++;
		while(w.count(m))m++;
	}
	r+=w.count(0);
	printf("%d\n",r);
	return 0;
}