#include<cstdio>
#include<algorithm>
using namespace std;

char w;
char s[11];
int main(){
	int n;
	scanf("%d",&n);
	printf("0 1\n");
	fflush(stdout);
	scanf("%s",s);
	w=s[0];
	int l=1,r=1e9;
	for(int i=2;i<=n;i++){
		int mid=l+r>>1;
		printf("%d 1\n",mid);
		fflush(stdout);
		scanf("%s",s);
		if(s[0]!=w)r=mid-1;
		else l=mid+1;
	}
	printf("%d %d %d %d\n",l-1,2,min(r+1,(int)1e9),0);
	fflush(stdout);
}