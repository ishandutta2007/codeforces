#include<bits/stdc++.h>
using namespace std;

int n,pos;
string s[2005],t[2005],magic;
string ss[2005],tt[2005];
char io[2005];
string read(){
	scanf("%s",io);
	return io;
}
void solve(vector<pair<string,int> >&events){
	for(int i=1;i<=n;i++){
		if(s[i][pos]!=t[i][pos]){
			events.push_back(make_pair("row",i-1));
			for(int j=1;j<=n;j++){
				if(magic[j]=='1'){
					s[i][j]='1'+'0'-s[i][j];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(s[pos][i]!=t[pos][i]){
			events.push_back(make_pair("col",i-1));
			for(int j=1;j<=n;j++){
				if(magic[j]=='1')s[j][i]='0'+'1'-s[j][i];
			}
		}
	}
	bool ok=true;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(s[i][j]!=t[i][j])ok=false;
	if(ok){
		printf("%u\n",events.size());
		for(int i=0;i<events.size();i++){
			pair<string,int>p=events[i];
			printf("%s %d\n",p.first.c_str(),p.second);
		}
		exit(0);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)s[i]=" "+read();
	for(int i=1;i<=n;i++)t[i]=" "+read();
	for(int i=1;i<=n;i++){
		ss[i]=s[i];tt[i]=t[i];
	}
	magic=" "+read();
	pos=0;
	for(int i=1;i<=n;i++)if(magic[i]=='1')pos=i;
	if(pos==0){
		for(int i=1;i<=n;i++)
			if(s[i]!=t[i]){
				printf("-1\n");
				return 0;
			}
		printf("0\n");
		return 0;
	}else{
		vector<pair<string,int> >events;
		solve(events);
		events.clear();
		events.push_back(make_pair("col",pos-1));
		for(int i=1;i<=n;i++){
			s[i]=ss[i];
		}
		for(int i=1;i<=n;i++)if(magic[i]=='1')s[i][pos]='1'+'0'-s[i][pos];
		solve(events);
	}
	cerr<<"no solution"<<endl;
	printf("-1\n");
	return 0;
}