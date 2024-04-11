#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&-x)
const int maxn=2e5+5,M=2e5+5,mod=998244353;
inline int read(){
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1){x=-x;}return x;
}
void print(int x){
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,a[maxn],b[maxn],tot=0,ans[maxn],c[maxn],id[maxn];
bool cmp(int x,int y){return a[x]<a[y];}
void solve(){
	random_shuffle(c+1,c+tot+1);
	int s1=a[c[1]],s2=0;ans[c[1]]=1;
	for(int i=2;i<=tot;i++){
		if(a[c[i]]%s1==0){
			ans[c[i]]=2;
			if(!s2)s2=a[c[i]];
			else if(a[c[i]]%s2!=0)s2=__gcd(s2,a[c[i]]);
		}else ans[c[i]]=1,s1=__gcd(s1,a[c[i]]);
	}//cout<<s1<<" "<<s2<<" "<<tot<<endl;
	if(s1!=1||s2!=1)return;
	puts("YES");
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	exit(0);
}
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();srand(time(0));
	for(int i=1;i<=n;i++)a[i]=read(),id[i]=i;
	sort(id+1,id+n+1,cmp);c[++tot]=id[1];
	for(int i=2;i<=n;i++)
		if(a[id[i]]!=a[id[i-2]])c[++tot]=id[i];
		else ans[id[i]]=1;
	while(1.0*clock()/CLOCKS_PER_SEC*1000<450)solve();
	puts("NO");
 	return 0;
}