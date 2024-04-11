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
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

int c0[32],c1[32],n;
char s[2048],t[2048],z[2048];
vector<int> r;

void op(int k){
	//printf(" %d\n",k);
	r.pb(k);
	fore(i,0,k)z[n-k+i]=s[i];
	fore(i,0,n-k)z[i]=s[n-1-i];
	mcopy(s,z);
	//puts(s);
}

int main(){
	scanf("%d%s%s",&n,s,t);
	fore(i,0,n)c0[s[i]-'a']++;
	fore(i,0,n)c1[t[i]-'a']++;
	fore(i,0,26)if(c0[i]!=c1[i]){puts("-1");return 0;}

	/*fore(k,0,n){ // sz of a
		int p;
		if(k%2==0)p=(n-1)/2-k/2;
		else p=(n-1)/2+(k+1)/2;
		//printf(" %d %d\n",k,p);
		assert(p>=0&&p<n);
		char c=t[p];int j=-1;
		printf(" %d %c\n",p,c);
		fore(i,k,n)if(s[i]==c){j=i;break;}
		assert(j>=0);
		//op(j);op(n-j);op(n-1);
		op(j);op(n-j);op(j);op(n);op(n-1)
	}*//*
	fore(k,0,n){
		int p;
		if(k%2==0)p=(n-1)/2-k/2;
		else p=(n-1)/2+(k+1)/2;
		//printf(" %d %d\n",k,p);
		assert(p>=0&&p<n);
		char c=t[p];int j=-1;
		printf(" %d %c\n",p,c);
		fore(i,0,n-k)if(s[i]==c){j=i;break;}
		assert(j>=0);
		op(j+1);op(0);op(1);
	}*/
	fore(k,0,n){
		int p=n-1-k;
		char c=t[p];int j=-1;
		//printf(" %d %c\n",p,c);
		fore(i,k,n)if(s[i]==c){j=i;break;}
		assert(j>=0);
		op(0);op(n-j);op(n-1);
	}
	if(strncmp(s,t,n))op(0);
	assert(!strncmp(s,t,n));
	printf("%d\n",SZ(r));
	fore(i,0,SZ(r))printf("%d%c",n-r[i]," \n"[i==SZ(r)-1]);
	return 0;
}