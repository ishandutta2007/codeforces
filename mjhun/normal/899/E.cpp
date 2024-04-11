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

int x[200005],a[200005],b[200005],l[200005];
int n,r;
set<pair<int,int> > s;

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",x+i);
	int z=-1,i=0;a[0]=n;
	while(i<n){
		int j=i;
		while(j<n&&x[j]==x[i])j++;
		s.insert(mp(i-j,i));
		a[j]=i;b[i]=j;l[i]=j-i;
		i=j;
	}
	while(SZ(s)){
		r++;
		int i=s.begin()->snd;s.erase(s.begin());
		if(a[i]<n&&b[i]<n&&x[a[i]]==x[b[i]]){
			s.erase(mp(-l[a[i]],a[i]));
			s.erase(mp(-l[b[i]],b[i]));
			l[a[i]]+=l[b[i]];
			b[a[i]]=b[b[i]];
			a[b[a[i]]]=a[i];
			s.insert(mp(-l[a[i]],a[i]));
		}
		else {
			b[a[i]]=b[i];
			a[b[i]]=a[i];
		}
	}
	printf("%d\n",r);
	return 0;
}