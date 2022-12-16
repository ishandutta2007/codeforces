#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

const int N=111;
int n,m;
int mo(int x){
	while(x<0)x+=n*m;
	while(x>=n*m)x-=n*m;
	return x;
}

int rot[N];
int rotate(int x,int d){
	rot[x]+=d;
	printf("? %d %d\n",x,d);
	fflush(stdout);
	return read();
	// static int s[4]={0,5,10,15};
	// s[x]=mo(s[x]+d);
	// int cover[10000]={0};
	// D(i,n)D(j,m)cover[mo(s[i]+j)]|=1<<i;
	// int ans=0;
	// D(i,n*m)ans+=!cover[i];
	// D(i,n){
	// 	D(j,n*m)cerr<<".*"[(cover[j]>>i)&1];
	// 	cerr<<endl;
	// }
	// cerr<<ans<<endl;
	// return ans;
}

int last;
int diff(int x,int d){
	int ll=last;
	last=rotate(x,d);
	return last-ll;
}

int pos[N];
bool found[N];
int main(){
	n=read();
	m=read();
	// n=4;
	// m=5;
	last=rotate(0,1);
	int root=-1;
	D(i,n){
		if(diff(i,1)==-1){
			root=i;
			break;
		}
	}
	assert(root!=-1);
	while(diff(root,-1)==1){}
	diff(root,1);
	diff(root,1);
	// cerr<<"start!"<<endl;
	pos[root]=0;
	found[root]=true;
	F(t,1,n-1){
		static int undone[N];
		int cundone=0;
		D(i,n)if(!found[i])undone[cundone++]=i;
		static int a[N],b[N];
		D(i,cundone){
			a[i]=diff(undone[i],1);
		}
		diff(root,-1);
		R(i,cundone-1,0){
			b[i]=-diff(undone[i],-1);
		}
		// D(i,cundone)cerr<<undone[i]<<" "<<a[i]<<" "<<b[i]<<endl;
		
		int got=-1;
		D(i,cundone){
			if(a[i]>b[i]&&b[i]==-1){
				assert(got==-1);
				got=undone[i];
			}
		}
		// cerr<<"got "<<got<<endl;
		assert(got!=-1);
		pos[got]=rot[root]-rot[got];
		found[got]=true;

		if(t!=n-1){
			D(_,m+1)diff(got,1);
			diff(root,1);
			while(diff(root,-1)==0){}
			while(diff(root,-1)==1){}
			diff(root,1);
			diff(root,1);
		}
	}
	printf("!");
	F(i,1,n-1)printf(" %d",mo(pos[i]+rot[i]-pos[0]-rot[0]));
	printf("\n");
	fflush(stdout);
	return 0;
}