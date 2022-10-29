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
bool h[32];
bool c[32];
int n;

int main(){
	scanf("%d",&n);
	memset(c,true,sizeof(c));
	char t[4];
	int k=-1,r=0;
	fore(_,0,n-1){
		scanf("%s%s",t,s);
		memset(h,false,sizeof(h));
		for(int i=0;s[i];++i)h[s[i]-'a']=true;
		if(t[0]=='!'){
			if(k>=0)r++;
			fore(i,0,26)if(!h[i])c[i]=false;
		}
		else if(t[0]=='.'){
			fore(i,0,26)if(h[i])c[i]=false;
		}
		else {
			if(k>=0)r++;
			c[s[0]-'a']=false;
		}
		if(k<0){
			int z=0;
			fore(i,0,26)z+=c[i];
			if(z==1)k=_;
		}
	}
	//assert(k>=0);
	scanf("%s%s",t,s);
	printf("%d\n",r);
	return 0;
}