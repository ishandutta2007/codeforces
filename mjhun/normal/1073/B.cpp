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

int n;
queue<int> q;
bool v[200005];

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		int a;
		scanf("%d",&a);
		q.push(a);
	}
	fore(i,0,n){
		int b,r=0;
		scanf("%d",&b);
		if(!v[b]){
			while(q.front()!=b)v[q.front()]=true,q.pop(),r++;
			v[b]=true;q.pop();r++;
		}
		printf("%d%c",r," \n"[i==n-1]);
	}
	return 0;
}