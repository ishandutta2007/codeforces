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

int o;

int n;
char t[300005];
char t2[300005];
int s[300005];

int main(){
	scanf("%d%s",&n,t);
	fore(i,0,n){
		s[i+1]=s[i]+(t[i]=='('?1:-1);
	}
	if(s[n]!=0){puts("0\n1 1");return 0;}
	pair<int,int> w=mp(1,-1);
	fore(i,0,n)w=min(w,mp(s[i],i));
	o=w.snd;
	fore(i,0,n)t2[i]=t[(i+o)%n];
	memcpy(t,t2,sizeof(t));
	fore(i,0,n){
		s[i+1]=s[i]+(t[i]=='('?1:-1);
	}
	//fore(i,1,n+1)printf(" %d\n",s[i]);
	int c=0;
	fore(i,1,n+1)c+=s[i]==0;
	pair<int,pair<int,int> > r=mp(c,mp(0,0));
	
	int i=1;
	while(i<=n){
		while(i<=n&&s[i]<2)i++;
		if(i>n)break;
		int q=0;
		int j=i;
		while(s[j]>=2){
			if(s[j]==2)q++;
			j++;
		}
		r=max(r,mp(c+q,mp(i-1,j-1)));
		i=j;
	}
	
	i=1;
	while(i<=n){
		while(i<=n&&s[i]<1)i++;
		if(i>n)break;
		int q=0;
		int j=i;
		while(s[j]>=1){
			if(s[j]==1)q++;
			j++;
		}
		r=max(r,mp(q,mp(i-1,j-1)));
		i=j;
	}
	
	printf("%d\n%d %d\n",r.fst,(r.snd.fst+o)%n+1,(r.snd.snd+o)%n+1);
	return 0;
}