#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

char f(char a, char b){
	char r;
	for(r='a';r==a||r==b;++r);
	return r;
}

int n,k;
char s[100005];
char t[100005];
char r[100005];
vector<int> e;
vector<int> d;

int main(){
	scanf("%d%d%s%s",&n,&k,s,t);
	fore(i,0,n){
		if(s[i]==t[i])e.pb(i);
		else d.pb(i);
	}
	if(k<(d.size()+1)/2){puts("-1");return 0;}
	while(!d.empty()){
		int i=d.back();
		if(k-1>=d.size()/2){
			r[i]=f(s[i],t[i]);
		}
		else {
			assert(d.size()>=2);
			d.pop_back();
			int j=d.back();
			r[i]=s[i];
			r[j]=t[j];
		}
		k--;
		d.pop_back();
	}
	while(!e.empty()){
		int i=e.back();e.pop_back();
		if(k>0)r[i]=f(s[i],t[i]),k--;
		else r[i]=s[i];
	}
	assert(k==0);
	puts(r);
	return 0;
}