#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int N=2e6+9;

int n;
char s[N];
bool vst[N];

bool check(int pos) {
	int x=n+1; pos=(s[n]=='R'&&pos?-pos:pos), pos=(!pos?pos:pos+n+1);
	//cout<<pos<<endl;
	rep(i,0,2*n+2) vst[i]=(i==n+1);
	rep(i,1,n-1) {
		int nx=(s[i]=='L'?x-1:x+1);
		vst[x=(nx!=pos?nx:x)]=1;
		//cout<<"	"<<x<<endl;
	}
	int nx=(s[n]=='L'?x-1:x+1);
	return !(nx==pos||vst[nx]);
}

signed main() {
	scanf("%s",s+1); n=strlen(s+1);
	int res=0;
	if(check(0)) {puts("1"); return 0;}
	for(int l=1,r=n,mid=(l+r)>>1;l<=r;mid=(l+r)>>1) {
		if(check(mid)) res=mid, l=mid+1;
		else r=mid-1; 
	}
	printf("%lld\n",res);
	return 0;
}