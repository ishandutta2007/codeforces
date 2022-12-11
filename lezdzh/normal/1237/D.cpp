#include<cstdio>
#include<algorithm>
using namespace std;

int a[300001],s[300001],b[300001];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i+n]=a[i+2*n]=a[i];
	}
	for(int i=3*n;i;i--){
		{
			int l=0,r=s[0];
			while(l!=r){
				int mid=l+r+1>>1;
				if(a[s[mid]]*2<a[i])l=mid;
				else r=mid-1;
			}
			b[i]=l==0?2e9:s[l];
		}
		while(s[0]&&a[i]<=a[s[s[0]]])
			s[0]--;
		s[++s[0]]=i;
	}
	for(int i=3*n-1;i;i--)
		b[i]=min(b[i],b[i+1]);
	for(int i=1;i<=n;i++)
		printf("%d%c",b[i]==2e9?-1:b[i]-i,i==n?'\n':' ');
}