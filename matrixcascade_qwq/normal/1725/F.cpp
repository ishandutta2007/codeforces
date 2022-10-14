#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> pr;
const int N=1e5+5;
const int Z=30;
vector<pr>in[Z];
int n,ans[Z];
inline int Read(){
	char ch;
	int f=1;
	while((ch=getchar())<'0'||ch>'9')
		if(ch=='-') f=-1;
	int x=ch^48;
	while((ch=getchar())>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+(ch^48);
	return x*f;
}
inline void print(int x){
	if(x>=10) print(x/10);
	putchar(x%10+48);
	return ;
}
inline void Print(int x,char ch='\n'){
	if(x<0){
		putchar('-');
		print(-x);
	}
	else print(x);
	putchar(ch);
	return ;
}
inline void Push(int k,int l,int r){
	in[k].push_back(make_pair(l,1));
	in[k].push_back(make_pair(r+1,-1));
	return ;
}
inline void Init(){
	n=Read();
	for(int i=1;i<=n;i++){
		int ll=Read(),rr=Read();
		for(int j=0;j<Z;j++){
			if(rr-ll+1>=(1<<j)){
				ans[j]++;
				continue ;
			}
			int l=ll%(1<<j),r=rr%(1<<j);
			if(l<=r) Push(j,l,r);
			else{
				Push(j,l,(1<<j)-1);
				Push(j,0,r);
			}
		}
	}
	return ;
}
inline int Max(int x,int y){
	return x>y?x:y;
}
inline int Min(int x,int y){
	return x<y?x:y;
}
inline void Cmax(int&x,int y){
	if(y>x) x=y;
	return ;
}
inline void Cmin(int&x,int y){
	if(y<x) x=y;
	return ;
}
inline void Get(int k){
	int ss=0;
	sort(in[k].begin(),in[k].end());
	int s1=0;
	for(int i=0;i<in[k].size();i++){
		ss+=in[k][i].second;
		if(i==in[k].size()-1||in[k][i].first!=in[k][i+1].first)
			Cmax(s1,ss);
	}
	ans[k]+=s1;
	return ;
}
int q;
inline void Solve(){
	for(int i=0;i<Z;i++)
		Get(i);
	for(q=Read();q;q--){
		int x=Read();
		for(int i=0;i<Z;i++)
			if(x&(1<<i)){
				Print(ans[i]);
				break ;
			}
	}
	return ;
}
int main(){
	Init();
	Solve();
	return 0;
}