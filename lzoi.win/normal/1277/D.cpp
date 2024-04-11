#include<cstdio>
#include<iostream>
#include<set>
using namespace std;
const int MAXN=2e5+5;
int n;
string a[MAXN];
set<string> s;
string GetRev(const string str){
	string res;
	for(int i=str.size()-1;i>=0;i--)
		res+=str[i];
	return res;
}
int t0,t1,c0,c1;
int ans[MAXN];
void Calc(){
	ans[0]=0;
	if(!c0&&!c1&&t0*t1){
		ans[0]=-1;
		return ;
	}
	for(int i=1; i<=n; i++){
		if(a[i][0]==a[i][a[i].size()-1]) continue;
		//printf("Deal %d\n",i);
		if(a[i][0]=='0'){
			if(c0<=c1) continue;
			if(c0-c1>1&&s.find(GetRev(a[i]))==s.end()) ans[++ans[0]]=i,c0--,c1++;
		}else if(c1-c0>1&&s.find(GetRev(a[i]))==s.end()) ans[++ans[0]]=i,c0++,c1--;
	}
	if(c0-c1>1||c1-c0>1) ans[0]=-1;
	//printf("end c0 %d c1 %d\n",c0,c1);
	return ;
}
int main(){
	//freopen("D.in","r",stdin);
	int t;cin>>t;
	while(t--){
		s.clear();
		cin>>n;
		t0=t1=c0=c1=0;
		for(int i=1; i<=n; i++){
			cin>>a[i];
			s.insert(a[i]);
			if(a[i][0]==a[i][a[i].size()-1]){
				if(a[i][0]=='0') t0=1;
				else t1=1;
			}else if(a[i][0]=='0') c0++;
			else c1++;
		}
		//printf("c0 %d c1 %d\n",c0,c1);
		Calc();
		printf("%d",ans[0]);
		if(~ans[0]) puts("");
		for(int i=1; i<=ans[0]; i++) printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}