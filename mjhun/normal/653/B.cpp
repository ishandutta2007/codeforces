#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

int n,q;
char s[64][4];
char t[64][4];
set<string> w;
int f[8][8];

int go(int k, int l){
	if(f[k][l]>=0)return f[k][l];
	if(k==n)return f[k][l]=1;
	int r=0;
	for(set<string>::iterator it=w.begin();it!=w.end();++it){
		string s=*it;
		if(s[2]=='a'+l){
			r+=go(k+1,s[0]-'a');
		}
	}
	return f[k][l]=r;
}

int main(){
	scanf("%d%d",&n,&q);
	fore(i,0,q){
		scanf("%s%s",s[i],t[i]);
		string a="";
		a+=s[i][0];
		a+=s[i][1];
		a+=t[i][0];
		w.insert(a);
	}
	memset(f,-1,sizeof(f));
	printf("%d\n",go(1,0));
	return 0;
}