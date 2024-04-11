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
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

int q[256],n;
char s[100005];

int doit(){
	scanf("%s",s);
	mset(q,0);
	for(int i=0;s[i];++i)q[s[i]]++;
	if(n==1&&*max_element(q,q+256)==strlen(s))return strlen(s)-1;
	return min(*max_element(q,q+256)+n,(int)strlen(s));
}

int main(){
	scanf("%d",&n);
	int a=doit();
	int b=doit();
	int c=doit();
	if(a>max(b,c))puts("Kuro");
	else if(b>max(a,c))puts("Shiro");
	else if(c>max(a,b))puts("Katie");
	else puts("Draw");
	return 0;
}