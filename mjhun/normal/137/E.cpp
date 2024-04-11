#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

bool isv[256];
char s[200005];
int sp[200005];
int n;
pair<int,int> w[200005];

int main(){
	isv['a']=isv['e']=isv['i']=isv['o']=isv['u']=isv['A']=isv['E']=isv['I']=isv['O']=isv['U']=1;
	scanf("%s",s);n=strlen(s);
	fore(i,1,n+1){
		sp[i]=sp[i-1];
		if(isv[s[i-1]])sp[i]--;
		else sp[i]+=2;
	}
	fore(i,0,n+1)w[i]=mp(-sp[i],i);
	sort(w,w+n+1);
	for(int i=n-1;i>=0;--i){
		w[i].snd=min(w[i].snd,w[i+1].snd);
	}
	int r0=0,r1=0;
	fore(i,1,n+1){
		r0=max(r0,i-lower_bound(w,w+n+1,mp(-sp[i],-1))->snd);
	}
	fore(i,r0,n+1)r1+=sp[i]-sp[i-r0]>=0;
	if(!r0)puts("No solution");
	else printf("%d %d\n",r0,r1);
	return 0;
}