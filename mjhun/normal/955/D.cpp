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

vector<int> kmppre(string& t){ // r[i]: longest border of t[0,i)
	vector<int> r(t.size()+1);r[0]=-1;
	int j=-1;
	fore(i,0,t.size()){
		while(j>=0&&t[i]!=t[j])j=r[j];
		r[i+1]=++j;
	}
	return r;
}

int n,m,k;
string s,t;
char _s[1<<19],_t[1<<19];
string ss;
vector<int> b0,b1;
map<int,int> w;

int main(){
	scanf("%d%d%d%s%s",&n,&m,&k,_s,_t);
	s=string(_s);t=string(_t);
	ss=t+'#'+s;
	b0=kmppre(ss);
	for(int i=n;i>=0;--i)if(b0[m+1+i]>=m){
		int s=max(i-2*k,0);
		printf("Yes\n%d %d\n",s+1,s+k+1);
		return 0;
	}
	//puts("holis");
	reverse(t.begin(),t.end());
	reverse(s.begin(),s.end());
	ss=t+'#'+s;
	b1=kmppre(ss);
	for(int i=0;i<SZ(b0);++i)if(b0[i]>k)b0[i]=b0[b0[i]];
	for(int i=0;i<SZ(b1);++i)if(b1[i]>k)b1[i]=b1[b1[i]];
	for(int i=n-k;i>=k;--i){ // donde termina el primero
		int a=b1[m+1+n-i];
		w[a]=i;
		if(i==n-k){
			a=b1[a];
			while(a>=0){
				w[a]=i;
				a=b1[a];
			}
		}
		int b=b0[m+1+i];
		if(w.count(m-b)){
			int r1=w[m-b];
			int r0=i-k;
			printf("Yes\n%d %d\n",r0+1,r1+1);
			return 0;
		}
		if(i==k){
			b=b0[b];
			while(b>=0){
				if(w.count(m-b)){
					int r1=w[m-b];
					int r0=i-k;
					printf("Yes\n%d %d\n",r0+1,r1+1);
					return 0;
				}
				b=b0[b];
			}
		}
	}
	puts("No");
	return 0;
}