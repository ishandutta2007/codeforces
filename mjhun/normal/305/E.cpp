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

char s[5005];int n;
int f[5005];
vector<pair<int,int> > w;

int main(){
	scanf("%s",s);n=strlen(s);
	f[0]=0;
	fore(i,1,5005){
		set<int> w;
		fore(j,0,i)w.insert(f[max(j-1,0)]^f[max(i-2-j,0)]);
		f[i]=0;
		while(w.count(f[i]))f[i]++;
	}
	int r=0;
	for(int i=1;i<n-1;){
		if(s[i-1]!=s[i+1]){i++;continue;}
		int j=i;
		while(j<n-1&&s[j-1]==s[j+1])j++;
		w.pb(mp(i,j));
		r^=f[j-i];
		i=j;
	}
	puts(r?"First":"Second");
	if(r){
		for(auto p:w){
			int i=p.snd-p.fst;
			fore(j,0,i)if(!(f[max(j-1,0)]^f[max(i-2-j,0)]^r^f[i])){
				printf("%d\n",p.fst+j+1);
				return 0;
			}
		}
		assert(0);
	}
	return 0;
}