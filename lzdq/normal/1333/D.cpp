#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=3005;
int n,k;
char s[MAXN];
bool a[MAXN];
int ans;
int mi,mx,sum;
int f[MAXN];
bool Calc(){
	sum=0;
	for(int i=1; i<n; i++)
		if(!a[i]&&a[i+1]){
			sum++;
			a[i]=1;
			a[i+1]=0;
			i++;
		}
	return sum;
}
int main(){
	//freopen("in3.txt","r",stdin);
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	for(int i=1; i<=n; i++)
		if(s[i]=='L') a[i]=1;
	while(Calc()){
		mi++;
		mx+=sum;
		//printf("sum %d\n",sum);
	}
	if(k<mi||k>mx) return puts("-1"),0;
	for(int i=1; i<=n; i++)
		if(s[i]=='L') a[i]=1;
		else a[i]=0;
	sum=k;
	for(int i=1; i<=mi; i++){
		vector<int> v;
		//for(int j=1; j<=n; j++) putchar(a[j]+'0'); puts("ff");
		for(int j=1; j<n; j++){
			if(a[j]||!a[j+1]) continue;
			if(sum>mi-i+1){
				printf("1 %d\n",j);
				swap(a[j],a[j+1]);
				j++;
				sum--;
				continue;
			}
			v.push_back(j);
			sum--;
		}
		if(v.empty()) continue;
		printf("%d ",v.size());
		for(int j=0;j<v.size();j++){
			printf("%d ",v[j]);
			swap(a[v[j]],a[v[j]+1]);
		}
		puts("");
	}
	return 0;
}