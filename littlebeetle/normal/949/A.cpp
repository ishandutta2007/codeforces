#include<cstdio>
#include<vector>
using namespace std;
const int N=400002;
int n,x,cnt;
int q1[N],t1,q2[N],t2;
char s[N];
vector<int>p[N];
int main(){
	scanf("%s",s+1);
	for(n=1;s[n];n++){
		if(s[n]==48){
			if(t2){
				x=q2[t2--];
				p[x].push_back(n);
				q1[++t1]=x;
			}
			else{
				x=++cnt;
				p[x].push_back(n);
				q1[++t1]=x;
			}
		}
		else{
			if(!t1){
				printf("-1");
				return 0;
			}
			x=q1[t1--];
			p[x].push_back(n);
			q2[++t2]=x;
		}
	}
	if(t2){
		printf("-1");
		return 0;
	}
	printf("%d\n",cnt);
	for(n=1;n<=cnt;n++){
		printf("%d ",p[n].size());
		for(x=0;x<p[n].size();x++)
			printf("%d ",p[n][x]);
		printf("\n");
	}
}