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

string s0="What are you doing at the end of the world? Are you busy? Will you save us?";
string s1="What are you doing while sending \"";
string s2="\"? Are you busy? Will you send \"";
string s3="\"?";
ll w[100005];

char get(int n, ll k){
	if(k>=w[n])return '.';
	if(n==0)return s0[k];
	if(k<SZ(s1))return s1[k];
	if(k-SZ(s1)<w[n-1])return get(n-1,k-SZ(s1));
	if(k-SZ(s1)-w[n-1]<SZ(s2))return s2[k-SZ(s1)-w[n-1]];
	if(k-SZ(s1)-w[n-1]-SZ(s2)<w[n-1])return get(n-1,k-SZ(s1)-w[n-1]-SZ(s2));
	return s3[k-SZ(s1)-w[n-1]-SZ(s2)-w[n-1]];
}

int main(){
	int q;
	scanf("%d",&q);
	w[0]=SZ(s0);
	fore(i,1,100005)w[i]=min(w[i-1]*2+SZ(s1)+SZ(s2)+SZ(s3),1LL<<60);
	while(q--){
		int n;ll k;
		scanf("%d%lld",&n,&k);k--;
		putchar(get(n,k));
	}
	puts("");
	return 0;
}