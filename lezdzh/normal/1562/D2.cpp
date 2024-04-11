#include<cstdio>

using namespace std;

char s[300002];
int a[300001];
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n,q;
		scanf("%d%d%s",&n,&q,s+1);
		for(int i=1;i<=n;i++)
			a[i]=a[i-1]+((s[i]=='+')^(i%2==1)?1:-1);
		for(int i=1;i<=q;i++){
			int l,r;
			scanf("%d%d",&l,&r);
			if(a[r]-a[l-1]==0)printf("0\n");
			else{
				int ll=l,rr=r,ok=0;
				if((r-l+1)%2==0)ok=1,l++,ll++;
				if(a[r]-a[l]==0)ll=rr=l;
				else if(a[r-1]-a[l-1]==0)ll=rr=r;
				else
				while(ll!=rr){
					int mid=ll+rr>>1;
					if((a[mid-1]-a[l-1]==a[r]-a[mid])||(a[mid-1]-a[l-1]>a[r]-a[mid])==(-a[r]+a[l]<0))
						rr=mid;
					else ll=mid+1;
				}
				if(ok)printf("2\n%d %d\n",l-1,ll);
				else printf("1\n%d\n",ll);
			}
		}
	}
}