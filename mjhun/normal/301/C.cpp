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

int main(){
	fore(i,0,10)printf("??%d>>%d??\n",i,i);
	puts("\?\?>>?");
	fore(i,0,9)printf("%d?<>%d\n",i,i+1);
	puts("9?>>?0\n?<>1");
	fore(i,0,10)printf("%d>>%d??\n",i,i);
	return 0;
}