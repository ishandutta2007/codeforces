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

void perdi(){puts("NO");exit(0);}

int n;
int x[100005],q[100005];

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",x+i);
	int mn=*min_element(x,x+n);
	int mx=*max_element(x,x+n);
	if(mx-mn>100002)perdi();
	fore(i,0,n)q[x[i]-mn]++;
	int k=0;
	q[0]--;
	fore(_,0,n-1){
		if(!k)k++;
		else if(k==1&&q[0])k--;
		else if(q[k-1]>1)k--;
		else if(q[k+1])k++;
		else k--;
		if(!q[k])perdi();
		q[k]--;
	}
	if(k!=1)perdi();
	puts("YES");
	return 0;
}