#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

char s[300005],t[300005];
char r[300005];
int n;
int ns,nt;
int is,js,it,jt;

int main(){
	scanf("%s%s",s,t);n=strlen(s);ns=(n+1)/2;nt=n/2;
	sort(s,s+n);s[ns]=0;
	sort(t,t+n);reverse(t,t+n);t[nt]=0;
	//puts(s);puts(t);
	is=it=0;js=ns-1;jt=nt-1;
	int i=0,j=n-1;
	fore(_,0,n){
		if(_%2==0){
			if(s[is]<t[it])r[i++]=s[is++];
			else r[j--]=s[js--];
		}
		else {
			if(t[it]>s[is])r[i++]=t[it++];
			else r[j--]=t[jt--];
		}
	}
	puts(r);
	return 0;
}