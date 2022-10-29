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

char s[100005];
int a[256];

int main(){
	a['a']=a['e']=a['i']=a['o']=a['u']=a['1']=a['3']=a['5']=a['7']=a['9']=1;
	scanf("%s",s);
	int r=0;
	for(int i=0;s[i];++i)r+=a[s[i]];
	printf("%d\n",r);
	return 0;
}