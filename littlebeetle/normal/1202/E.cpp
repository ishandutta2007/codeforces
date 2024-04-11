#include<cstdio>
#include<queue>
using namespace std;
const int N=210002;
char t[N],T[N],s[N],S[N];
int n,Len,i,j;
queue<int>Q;
long long Ans;
struct AC{
	int t[N][26],fail[N],d[N],cnt,ans[N];
	void Push(char *s){
		for(i=1,j=1;s[j];j++){
			if(!t[i][s[j]-97])
				t[i][s[j]-97]=++cnt;
			i=t[i][s[j]-97];
		}
		d[i]++;
	}
	void Build(){
		for(i=0;i<26;i++)
			if(t[1][i])
				fail[t[1][i]]=1,
				d[t[1][i]]+=d[1],
				Q.push(t[1][i]);
			else
				t[1][i]=1;
		while(!Q.empty()){
			i=Q.front();
			Q.pop();
			for(j=0;j<26;j++)
				if(t[i][j])
					fail[t[i][j]]=t[fail[i]][j],
					d[t[i][j]]+=d[fail[t[i][j]]],
					Q.push(t[i][j]);
				else
					t[i][j]=t[fail[i]][j];
		}
	}
	void work(char *s){
		for(i=1,j=1;s[j];j++){
			i=t[i][s[j]-97];
			ans[j]=d[i];
		}
	}
}T1,T2;
int main(){
	scanf("%s%d",t+1,&n);
	T1.cnt=1;
	T2.cnt=1;
	while(n--){
		scanf("%s",s+1);
		T1.Push(s);
		for(Len=0;s[Len+1];Len++);
		for(i=1;i<=Len;i++)
			S[i]=s[Len-i+1];
		S[i]=0;
		T2.Push(S);
	}
	T1.Build();
	T2.Build();
	T1.work(t);
	for(Len=0;t[Len+1];Len++);
	for(i=1;i<=Len;i++)
		T[i]=t[Len-i+1];	
	T2.work(T);
	for(i=1;i<Len;i++)
		Ans=Ans+1ll*T1.ans[i]*T2.ans[Len-i];
	printf("%I64d",Ans);
	return 0;
}