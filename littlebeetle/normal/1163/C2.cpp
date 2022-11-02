#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000002;
typedef long long ll;
struct p{
    ll x,y,u,v;
    bool operator<(const p &k)const{
        if(k.x!=x)return k.x<x;
        if(k.y!=y)return k.y<y;
        if(k.u!=u)return k.u<u;
        return k.v<v;
    }
}a[N];
ll n,m,x[N],y[N],i,j,k,s[N],sum,cnt;
ll ans,sum1,sum2;
ll Abs(ll x){
    return x>0?x:-x;
}
ll gcd(ll x,ll y){
    return y?gcd(y,x%y):x;
}
int main(){
    scanf("%I64d",&n);
    for(i=1;i<=n;i++)
        scanf("%I64d%I64d",x+i,y+i);
    for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++){
			m++;
			a[m].x=x[i]-x[j];
			a[m].y=y[i]-y[j];
			if(a[m].x==0)a[m].y=1;
			else if(a[m].y==0)a[m].x=1;
			else{
				if(a[m].x<0)
					a[m].x=-a[m].x,a[m].y=-a[m].y;
				k=gcd(Abs(a[m].x),Abs(a[m].y));
				a[m].x/=k;
				a[m].y/=k;
			}
			if(a[m].x==0)
				a[m].u=x[i];
			else{
				a[m].u=y[i]*a[m].x-x[i]*a[m].y;
				a[m].v=a[m].x;
				if(a[m].u<0)
					a[m].u=-a[m].u,a[m].v=-a[m].v;
				k=gcd(Abs(a[m].u),Abs(a[m].v));
				a[m].u/=k;
				a[m].v/=k;
			}
		}
    sort(a+1,a+m+1);
	sum=1;
	for(i=2;i<=m+1;i++){
		//printf("%I64d %I64d %I64d %I64d\n",a[i-1].x,a[i-1].y,a[i-1].u,a[i-1].v);
		if(a[i].x==a[i-1].x&&a[i].y==a[i-1].y){
			sum++;
			if(a[i].u==a[i-1].u&&a[i].v==a[i-1].v)
				sum--;
		}
		else
			s[++cnt]=sum,sum=1;
	}	
	sum=0;
	for(i=1;i<=cnt;i++){
		//printf("%I64d\n",s[i]);
		ans+=s[i]*sum,sum+=s[i];
	}
    printf("%I64d",ans);
	//while(1);
}