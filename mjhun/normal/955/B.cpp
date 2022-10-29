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

char s[100005];
int q[32];

bool can(int q1, int q2){
	if(q1+q2>4)return false;
	int a=q1+2*q2;
	return a>=4;
}

int main(){
	scanf("%s",s);
	for(int i=0;s[i];++i)q[s[i]-'a']++;
	int q1=0,q2=0;
	fore(i,0,26){
		if(q[i]==1)q1++;
		if(q[i]>1)q2++;
	}
	puts(can(q1,q2)?"Yes":"No");
	return 0;
}