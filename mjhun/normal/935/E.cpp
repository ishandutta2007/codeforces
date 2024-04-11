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

#define INF ((1LL<<30)-1)

char s[10005];
int a[10005],b[10005];int n;
stack<int> st;int p,m;bool asd;
ll f[10005][128][2];

int main(){
	scanf("%s%d%d",s,&p,&m);
	if(!s[1]){puts(s);return 0;}
	for(int i=0;s[i];++i){
		if(s[i]=='(')a[n]=b[n]=-99,st.push(n++);
		else if(s[i]==')'){
			int k=st.top();assert(a[k]>=-9&&b[k]>=-9);st.pop();
			if(!st.empty()){
				int j=st.top();
				if(a[j]<-9)a[j]=k;
				else b[j]=k;
			}
		}
		else if(s[i]>='0'&&s[i]<='9'){
			int j=st.top();
			if(a[j]<-9)a[j]=-(s[i]-'0');
			else b[j]=-(s[i]-'0');
		}
	}
	assert(st.empty());
	if(m<p)swap(m,p),asd=true;
	for(int i=n-1;i>=0;--i)fore(j,0,p+1){
		f[i][j][0]=INF;f[i][j][1]=-INF;
		if(a[i]<0&&b[i]<0){
			if(j==1&&!asd||j==0&&asd){
				f[i][j][0]=f[i][j][1]=-a[i]-b[i];
			}
			else if(j==1&&asd||j==0&&!asd){
				f[i][j][0]=f[i][j][1]=-a[i]+b[i];
			}
		}
		else if(a[i]<0){
			if(j-(!asd)>=0){
				f[i][j][0]=-a[i]+f[b[i]][j-(!asd)][0];
				f[i][j][1]=-a[i]+f[b[i]][j-(!asd)][1];
			}
			if(j-asd>=0){
				f[i][j][0]=min(f[i][j][0],-a[i]-f[b[i]][j-asd][1]);
				f[i][j][1]=max(f[i][j][1],-a[i]-f[b[i]][j-asd][0]);
			}
		}
		else if(b[i]<0){
			if(j-(!asd)>=0){
				f[i][j][0]=f[a[i]][j-(!asd)][0]-b[i];
				f[i][j][1]=f[a[i]][j-(!asd)][1]-b[i];
			}
			if(j-asd>=0){
				f[i][j][0]=min(f[i][j][0],f[a[i]][j-asd][0]+b[i]);
				f[i][j][1]=max(f[i][j][1],f[a[i]][j-asd][1]+b[i]);
			}
		}
		else {
			fore(k,0,j+1){
				if(j-(!asd)-k>=0){
					f[i][j][0]=min(f[i][j][0],f[a[i]][k][0]+f[b[i]][j-(!asd)-k][0]);
					f[i][j][1]=max(f[i][j][1],f[a[i]][k][1]+f[b[i]][j-(!asd)-k][1]);
				}
				if(j-asd-k>=0){
					f[i][j][0]=min(f[i][j][0],f[a[i]][k][0]-f[b[i]][j-asd-k][1]);
					f[i][j][1]=max(f[i][j][1],f[a[i]][k][1]-f[b[i]][j-asd-k][0]);
				}
			}
		}
		f[i][j][0]=min(f[i][j][0],INF);
		f[i][j][1]=max(f[i][j][1],-INF);
	}
	printf("%lld\n",f[0][p][1]);
	return 0;
}