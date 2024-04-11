#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

int n;
int a[100005],b[100005];
int pa[100005],pb[100005];
set<int> e[100005];
multiset<int> w0,w1;

int main(){
	w0.insert(1<<30);w1.insert(1<<30);
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",a+i),a[i]--,pa[a[i]]=i;
	fore(i,0,n)scanf("%d",b+i),b[i]--,pb[b[i]]=i;
	fore(i,0,n){
		if(pb[i]<=pa[i]){
			w1.insert(pa[i]-pb[i]);
			e[pb[i]+n-pa[i]].insert(i);
		}
		else {
			w0.insert(pb[i]-pa[i]);
			e[pb[i]-pa[i]].insert(i);
		}
		e[pb[i]+1].insert(i);
	}
	printf("%d\n",min(*w0.begin(),*w1.begin()));
	fore(i,1,n){
		for(int x:e[i]){
			if(i==pb[x]+1){
				// r+i=pa[x]+1
				w1.erase(w1.find(pa[x]+1-i));
				if(pa[x]==n-1){
					// r+i=0
					w1.insert(-i);
				}
				else {
					// r-i=n-1-pa[x]
					w0.insert(n-1-pa[x]+i);
				}
			}
			else {
				// r-i=0
				w0.erase(w0.find(i));
				// r+i=0
				w1.insert(-i);
			}
		}
		printf("%d\n",min(*w0.begin()-i,*w1.begin()+i));
	}
	return 0;
}