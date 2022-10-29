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
#define mset(x,a) (memset((x),(a),sizeof(x)))
#define mcpy(x,y) (memcpy((x),(y),sizeof(x)))
using namespace std;
typedef long long ll;

int n;
char s[200005],t[200005];
int w[32][32];

int main(){
	scanf("%d%s%s",&n,s,t);
	int r=n,a=-2,b=-2;
	mset(w,-1);
	fore(i,0,n){
		if(s[i]==t[i])r--;
		else w[s[i]-'a'][t[i]-'a']=i;
	}
	fore(i,0,26){
		fore(j,i+1,26)if(w[i][j]>=0&&w[j][i]>=0){
			a=w[i][j];b=w[j][i];
			r-=2;
			break;
		}
		if(a>=0)break;
	}
	if(a<0){
		fore(i,0,26){
			fore(j,0,26)if(w[i][j]>=0){
				fore(k,0,26)if(w[k][i]>=0){
					a=w[i][j];b=w[k][i];
					r--;
					break;
				}
				if(a>=0)break;
			}
			if(a>=0)break;
		}
	}
	printf("%d\n%d %d\n",r,a+1,b+1);
	return 0;
}