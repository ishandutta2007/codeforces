#include<bits/stdc++.h>
#define int long long
const int N=300005;
using namespace std;

int n;
int a[N],b[N];
int res[N];

void exgcd(int a,int b,int&x,int&y){
	if(b)exgcd(b,a%b,y,x),y-=a/b*x;
	else x=1,y=0;
}

void solve(){
	cin>>n;
	int sum=0;
	priority_queue<int> q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
	for(int i=1;i<=n;i++){
		q.push(b[i]-a[i]);
	}
	res[0]=sum;
	for(int i=1;i<=n;i++){
		sum+=q.top();
		q.pop();
		res[i]=sum;
	}
	int m;cin>>m;
	while(m--){
		int x,y;cin>>x>>y;
		swap(x,y);
		int d=__gcd(x,y);
		int l=x*y/d;
		int A,B;
		exgcd(x,y,A,B);
		x/=d,y/=d;
		A*=(n/d);
		B*=(n/d);
		int g=y,p=(A%g+g)%g;
		int dis=(p-A)/g;
		A+=dis*g,B-=dis*x;
		if(B<0||n%d){
			cout<<-1<<'\n';
			continue;
		}
		int L=A*x*d,R=L+(n-L)/l*l;
		while(R-L>l){
			int mid=(L+((R-L)>>1)/l*l);
			if(res[mid]>res[mid+l])R=mid;
			else L=mid; 
		}
		cout<<max(res[L],res[R])<<'\n';
	}
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;//cin>>_T;
	while(_T--)solve();
}