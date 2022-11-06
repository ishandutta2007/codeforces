#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mpr make_pair
#define fi first
#define se second
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
#define N 1009
using namespace std;

int n;
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
bool check(int a,int b,int c,int d){
	if (a<=0 || b<=0 || c<=0 || d<=0) return 0;
	if (a>n || b>n || c>n || d>n) return 0;
	if (a>c || b>d) return 0;
	printf("? %d %d %d %d\n",a,b,c,d); fflush(stdout);
	char ch[10]; scanf("%s",ch); return ch[0]=='Y';	
}
char ch[1009];
int main(){
	scanf("%d",&n);
	int i,x=1,y=1,now=n-1<<1;
	for (i=1; i<=n-1; i++){
		if (check(x,y+1,n,n)){
			y++; ch[i]='R';	
		} else{
			x++; ch[i]='D';
		}
	}
	for (i=1,x=y=n; i<=n-1; i++)
		if (check(1,1,x-1,y)){
			x--; ch[now--]='D';
		} else{
			y--; ch[now--]='R';
		}
	printf("! %s\n",ch+1);
	return 0;
}