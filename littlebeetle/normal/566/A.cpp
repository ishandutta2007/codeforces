#include<cstdio>
#include<vector>
using namespace std;
const int N=800003;
int n,cnt=1,i,ans,x[N],y[N],k;
char s[N];
vector<int>A[N],B[N];
struct Tire{
	int ch[N][26],a[N],b[N],dep[N];
	void insert(char *s,int opt,int id){
		int i,j;
		for(i=1,j=1;s[j];j++){
			if(!ch[i][s[j]-97]){
				ch[i][s[j]-97]=++cnt;
				dep[cnt]=dep[i]+1;
			}
			i=ch[i][s[j]-97];
		}
		if(opt&1){
			a[i]++;
			A[i].push_back(id);
		}
		else{
			b[i]++;
			B[i].push_back(id);
		}
	}
	void merge(int x,int y){
		while(A[y].size()){
			A[x].push_back(A[y].back());
			A[y].pop_back();
		}
		while(B[y].size()){
			B[x].push_back(B[y].back());
			B[y].pop_back();
		}	
	}	
	void dfs(int i){
		for(int j=0;j<26;j++){
			if(ch[i][j])
				dfs(ch[i][j]);
			a[i]+=a[ch[i][j]];
			b[i]+=b[ch[i][j]];
			merge(i,ch[i][j]);
		}
		int p=a[i]<b[i]?a[i]:b[i];
		ans+=p*dep[i];
		a[i]-=p;
		b[i]-=p;
		while(A[i].size()&&B[i].size()){
			k++;
			x[k]=A[i].back();
			y[k]=B[i].back();
			A[i].pop_back();
			B[i].pop_back();
		}
	}
}T;
void init(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%s",s+1);
		T.insert(s,1,i);
	}
	for(i=1;i<=n;i++){
		scanf("%s",s+1);
		T.insert(s,2,i);
	}
}
void work(){
	T.dfs(1);
	printf("%d\n",ans);
	for(i=1;i<=n;i++)
		printf("%d %d\n",x[i],y[i]);
	//while(1);
}
int main(){
	init();
	work();
}